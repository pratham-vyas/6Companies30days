class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> st;
        for (string& s : tokens) {
            if (!map.count(s)) {
                st.push(stoi(s));
            } else {
                int op1 = stack.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(map[s](op2, op1));
            }
        }
        return st.top();
    }
};