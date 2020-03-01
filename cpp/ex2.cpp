#include <bits/stdc++.h>

using namespace std;

struct{
    bool operator()(string a, string b) const
        {   
            if (a.size() > b.size()) {
                return true;
            } else if (a.size() < b.size()) {
                return false;
            } else {
                int n = a.length();
                char sa[n + 1];
                char sb[n + 1]; 
                strcpy(sa, a.c_str());
                strcpy(sb, b.c_str()); 

                for (int i = 0; i < a.size(); i++) {
                    int i_a = sa[i];
                    int i_b = sb[i];
                    if (i_a > i_b) {
                        return true;
                    } else if (i_a < i_b) {
                        return false;
                    }
                }
                return false;
            }
            
        }   
} customMore;

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {

    sort(unsorted.begin(),unsorted.end(),customMore);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
