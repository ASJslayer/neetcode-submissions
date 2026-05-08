class Solution:

    def encode(self, strs: List[str]) -> str:
        final_str = ""
        for string in strs:
            new_str = "#" + str(len(string)) + "#" + string
            final_str += new_str
        final_str = str(len(strs)) + final_str
        print(final_str)

        return final_str

    def decode(self, s: str) -> List[str]:
        num_strs = s[0]
        if (num_strs == '0'):
            return []
        s = s[1::]
        result = []
        state = "start"
        str_len = 0
        temp_str = ""
        for c in s:
            if (c == '#' and state == "start"):
                state = "read_num"
                continue
            if (c == "#" and state == "read_num"):
                state = "read_str"
                continue
            if (state == "read_num"):
                str_len = (str_len * 10) + int(c)
                continue
            if (state == "read_str" and len(temp_str) < str_len):
                temp_str += c
                continue
            if (state == "read_str" and len(temp_str) == str_len and c == '#'):
                result.append(temp_str)
                str_len = 0
                temp_str = ""
                state = "read_num"
                continue
            
            print("Invalid combo")


        result.append(temp_str)
        return result






