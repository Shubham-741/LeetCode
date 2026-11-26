class Solution {
public:
    bool canAliceWin(int n) {

        int turn = 1;

        int remove = 10;

        while(n>=remove){
            if(turn == 1){
                n -= remove;
                turn = 0;
                remove -= 1;
            }
            else{
                n -= remove;
                turn  = 1;
                remove -= 1;
            }
        }

        if (turn == 1){
            return false;
        }

        return true;
        
    }
};