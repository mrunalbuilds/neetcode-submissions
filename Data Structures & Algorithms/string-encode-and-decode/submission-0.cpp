class Solution {
public:

    string encode(vector<string>& strs) {
        // Store lengths with strings
        string original;
        for (const string &s : strs) {
            original += to_string(s.size()) + "#" + s;
        }

        // Original -> binary
        string binary;
        for (char c : original) {
            binary += bitset<8>((unsigned char)c).to_string();
        }

        int binaryLength = binary.size();

        string base64Chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789+/";

        // Binary -> Base64
        string encoded;
        for (int i = 0; i < binary.size(); i += 6) {
            string chunk = binary.substr(i, 6);
            while (chunk.size() < 6)
                chunk += '0';

            int value = 0;
            for (char bit : chunk)
                value = value * 2 + (bit - '0');

            encoded += base64Chars[value];
        }

        // Store binary length before encoded data
        return to_string(binaryLength) + "#" + encoded;
    }

    vector<string> decode(string s) {
        string base64Chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789+/";

        unordered_map<char, int> mp;
        for (int i = 0; i < 64; i++)
            mp[base64Chars[i]] = i;

        // Read stored binary length
        int pos = s.find('#');
        int binaryLength = stoi(s.substr(0, pos));
        string encoded = s.substr(pos + 1);

        // Base64 -> binary
        string binary;
        for (char c : encoded) {
            int value = mp[c];

            for (int i = 5; i >= 0; i--)
                binary += ((value >> i) & 1) + '0';
        }

        // Remove padding bits
        binary = binary.substr(0, binaryLength);

        // Binary -> original string
        string original;
        for (int i = 0; i + 8 <= binary.size(); i += 8) {
            int value = 0;

            for (int j = 0; j < 8; j++)
                value = value * 2 + (binary[i + j] - '0');

            original += char(value);
        }

        // Parse lengths
        vector<string> result;
        int i = 0;

        while (i < original.size()) {
            int j = i;

            while (original[j] != '#')
                j++;

            int len = stoi(original.substr(i, j - i));
            j++;

            result.push_back(original.substr(j, len));

            i = j + len;
        }

        return result;
    }
};
