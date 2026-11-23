class Solution {
public:
    int reverse(int x) {
        
        int y =0;
        int t;

        while(x != 0){
            t = x % 10;

            if (y > INT_MAX / 10 || (y == INT_MAX / 10 && t > 7)) {
                return 0;
            }
            if (y < INT_MIN / 10 || (y == INT_MIN / 10 && t < -8)) {
                return 0;
            }
            
            y = y*10 + t;
            x = x/10;
        }

        return y;
    }
};