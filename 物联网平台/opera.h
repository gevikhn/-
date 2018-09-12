#pragma once




void write(const char *filename);
void read(const char *filename);
void del(const char*filename);
int search_pos(const char *filename, int id);
int search_poss(const char *filename, int id);
void edit(const char *filename);
void edit_poss(const char *filename,int id, int value);
void search(const char *filename);
int value_search(const char *filename, int id);

