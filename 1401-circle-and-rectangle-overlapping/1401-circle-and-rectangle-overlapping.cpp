class Solution {
public:

    bool overlap(double a, double b, double c, double d) {
        return a <= d && c <= b;
    }

    bool checkOverlap(int r, int xc, int yc,
                      int x1, int y1, int x2, int y2) {

        // Left side: x = x1
        int val = r*r - (x1-xc)*(x1-xc);

        if (val >= 0) {
            double y3 = yc + sqrt(val);
            double y4 = yc - sqrt(val);

            if (overlap(y1, y2, y4, y3))
                return true;
        }

        // Bottom side: y = y1
        val = r*r - (y1-yc)*(y1-yc);

        if (val >= 0) {
            double x3 = xc + sqrt(val);
            double x4 = xc - sqrt(val);

            if (overlap(x1, x2, x4, x3))
                return true;
        }

        // Right side: x = x2
        val = r*r - (x2-xc)*(x2-xc);

        if (val >= 0) {
            double y3 = yc + sqrt(val);
            double y4 = yc - sqrt(val);

            if (overlap(y1, y2, y4, y3))
                return true;
        }

        // Top side: y = y2
        val = r*r - (y2-yc)*(y2-yc);

        if (val >= 0) {
            double x3 = xc + sqrt(val);
            double x4 = xc - sqrt(val);

            if (overlap(x1, x2, x4, x3))
                return true;
        }

        int xmnc = xc-r;
        int xmxc = xc+r;
        int ymnc = yc-r;
        int ymxc = yc+r;

        if((x1 <= xmnc && x2 >= xmxc && y1 <= ymnc && y2 >= ymxc) || (x1 >= xmnc && x2 <= xmxc && y1 >= ymnc && y2 <= ymxc))return true;

        return false;
    }
};