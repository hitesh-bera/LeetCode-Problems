class Solution {
public:
    long long minimumCost(int c1, int c2, int c3, int n1, int n2) {
        if(n1 == 0 && n2 == 0)return 0;
        
        long long takenC3 = 0;

        if(c3 < c1 + c2){ //take c3
            takenC3 = min(n1, n2);
        }

        n1 -= takenC3;
        n2 -= takenC3;

        long long cost = 1LL * takenC3 * c3;

        cost += (c3 < c1)? 1LL * n1 * c3 : 1LL * n1 * c1; 
        cost += (c3 < c2)? 1LL * n2 * c3 : 1LL * n2 * c2; 

        return cost;
    }
};