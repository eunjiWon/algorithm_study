#include <string>
#include <set>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, P> PP;

const int dy[4] = { 1, 0, -1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int solution(string dirs)
{
   set<PP> s;

   int y = 0, x = 0;
   int cnt = 0;

   for (int i = 0; i < dirs.size(); ++i) {
      int d;
      switch (dirs[i]) {
      case 'U': d = 0; break;
      case 'R': d = 1; break;
      case 'D': d = 2; break;
      case 'L': d = 3; break;
      }
      int ny = y + dy[d];
      int nx = x + dx[d];
      bool flag = false;
      if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5)flag = true;

      if (flag) {
         if (!s.count(PP(P(y, x), P(ny, nx))) && !s.count(PP(P(ny, nx), P(y, x)))) {
            ++cnt;
            s.insert(PP(P(y, x), P(ny, nx)));
         }
         y = ny, x = nx;
      }


   }
   return cnt;
}