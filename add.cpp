#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
  freopen ("index.html", "a", stdout);
  argv[1][strlen(argv[1])-4] = '\0';
  printf ("<li><a href = \"%s.cpp\">%s</a></li><br/>\n", argv[1], argv[1]);
  return 0;
}
