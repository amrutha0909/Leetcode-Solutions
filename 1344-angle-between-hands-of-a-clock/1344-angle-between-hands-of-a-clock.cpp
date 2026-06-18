class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle=abs(30*hour-5.5*minutes);
        return min(360-angle,angle);
    }
};