void computeLPSarray(string pat, int m, vector<int>& lps) {
        int j = 0;
        lps[0] = 0;
        int i = 1;
        while(i < m) {
                if(pat[i] == pat[j]) {
                        j++;
                        lps[i] = j;
                        i++;
                }
                else {
                        if(j != 0) {
                                j = lps[j - 1];
                        }
                        else {
                                lps[i] = 0;
                                i++;
                        }
                }
        }
}

void KMP(string a, string pat) {
        int n = a.size();
        int m = pat.size();

        vector<int> lps(n);

        computeLPSarray(pat, m, lps);

        int i = 0;
        int j = 0;

        while(i < n) {
                if(pat[i] == pat[j]) {
                        j++;
                        i++;
                }
                if(j == m) {
                        cout <<"MATCH \n";
                        return;
                }
                else if(i < n && pat[j] != pat[i]) {
                        if(j != 0)
                                j = lps[j - 1];
                        else i++;
                }
        }
}




void solve() {
        string a = "aaaaaaaaaaaaaaaaaaandndnndnndnsjsjcn";
        string b = "sdnjfnmdsnfjebfjsnnkjdfdnsjfndjfnjdnfjdaaaaaaaaaaaaaaaaaaaaaaadfn" + a;
        KMP(b, a);
}
