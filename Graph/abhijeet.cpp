#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define ll long long

int calculateExhibitionValue(int n, vector<string>& artworks) {
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        stringstream ss(artworks[i]);
        string type, name, temp;
        ll base;
        int age, con, sa;

        getline(ss, type, ':');
        getline(ss, name, ':');
        getline(ss, temp, ':');
        base = stoll(temp);
        getline(ss, temp, ':');
        age = stoi(temp);
        getline(ss, temp, ':');
        con = stoi(temp);
        getline(ss, temp);
        sa = stoi(temp);

        double curr = 0.0;
        
        if (type == "painting") {
            ll age = (ll)age * 10;
            ll f = (ll)sa * 100;
            double cm = con / 10.0;
            curr = (double)(base + age + f) * cm;
        } else if (type == "sculpture") {
            ll age = (ll)age * 15;
            ll mat = (ll)sa * 500;
            double cm = con / 10.0;
            curr = (double)(base + age + mat) * cm;
        } else if (type == "digital") {
            ll inn = (ll)sa * 50;
            double mo = base * 0.5;
            double cm = con / 10.0;
            curr = (base + inn + mo) * cm;
        }

        ans += round(curr);
    }

    return static_cast<int>(ans);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<string> artworks(n);
    for (int i = 0; i < n; ++i) {
        cin >> artworks[i];
    }

    int result = calculateExhibitionValue(n, artworks);
    cout << result << endl;

    return 0;
}