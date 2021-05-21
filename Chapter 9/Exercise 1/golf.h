#pragma once

const int LEN = 40;

struct golf
{
    char fullname[LEN];
    int handicap;
};


void setgolf(golf& golf, const char* name, int handicap);
int setgolf(golf& golf);

inline void handicap(golf& golf, int handicap);

void showgolf(const golf& golf);
