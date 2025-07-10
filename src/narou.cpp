#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include "StringUtil.h"

using namespace std;
#define N 30
#define M 100
int u8len(const char *str)
{
    int count = 0; // 文字数のカウント用
    while (*str != '\0')
    {
        if ((*str & 0xC0) != 0x80)
        {
            count++;
        } //
        str++;
    }
    return count;
}

int main()
{
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(1, 890000);
    vector<int> rnd;
    for (int n = 0; n < 10000; n++)
        rnd.vector::push_back(distr(eng));
    sort(rnd.begin(), rnd.end());
    unique(rnd.begin(), rnd.end());
    string str_buf;
    string input_csv_file_path = "narou_data_1.csv";
    int i = 0, j = 0, tail = 0;
    double stitleNoW = 0, sfav_novel_cnt = 0;
    int dataI[N * M][2] = {0};
    ifstream ifs(input_csv_file_path);
    if (!ifs)
    {
        cout << "Error! File can not be opened" << endl;
        return 0;
    }

    while (getline(ifs, str_buf))
    {
        if (i == rnd[tail])
        {
            cout << i << endl;
            string tmp = "";
            istringstream i_stream(str_buf);
            while (getline(i_stream, tmp, ','))
            {
                if (j == 0)
                    dataI[tail][j] = u8len(tmp.c_str());
                else if (j == 1)
                    dataI[tail][j] = stoi(tmp);
                else
                    break;
                j++;
            }
            j = 0;
            tail++;
        }
        i++;
        if (i > rnd[N * M - 1])
        {
            break;
        }
    }

    ofstream ofs("sampling.csv");

    for (int k = 0; k < N * M; k++)
    {
        for (int l = 0; l < 2; l++)
        {
            if (dataI[k][1] != 0)
                ofs << dataI[k][l] << ",";
        }
        if (dataI[k][1] != 0)
            ofs << endl;
    }

    /*
        for (int k = 0; k < 50, k++)
        {
            for (int l = 0; l < 30; l++)
            {
                stitleNoW += dataI[50 * k + l][0];
                sfav_novel_cnt += dataI[50 * k + l][1];
            }
            titleNoW[k] = stitleNoW / 30;
            fav_novel_cnt[k] = sfav_novel_cnt / 30;
        }
    */
    return 0;
}