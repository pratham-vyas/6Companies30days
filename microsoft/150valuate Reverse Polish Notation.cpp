typedef long long ll;
class Solution {
public:
    ll evalRPN(vector<string>& tokens) {
        unordered_map<string, function<ll (ll, ll) > > map = {
            { "+" , [] (ll a, ll b) { return a + b; } },
            { "-" , [] (ll a, ll b) { return a - b; } },
            { "*" , [] (ll a, ll b) { return a * b; } },
            { "/" , [] (ll a, ll b) { return a / b; } }
        };
        std::stack<ll> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                ll op1 = stack.top();
                stack.pop();
                ll op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};