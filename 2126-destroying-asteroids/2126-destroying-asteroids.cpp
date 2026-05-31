class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        unsigned long long currentMass = mass;
        for (int asteroid : asteroids) {
            if (currentMass < asteroid)
                return false;
            currentMass += asteroid;
        }
        return true;
    }
};