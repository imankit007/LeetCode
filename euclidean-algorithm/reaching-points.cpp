class Solution {
public:
    bool solve(int sx, int sy, int tx, int ty){

      if(sx==tx && sy==ty) return true;

      if(sx>tx || sy>ty) return false;

      return solve(sx+sy,sy,tx,ty) || solve(sx,sy+sx,tx,ty);
      
    }

    bool solve1(int sx, int sy, int tx, int ty){

        while(sx<tx && sy<ty){
          if(tx>ty)
            tx%=ty;
          else
            ty%=tx;
        }
       
        
        return sx==tx && sy<=ty && (ty-sy)%sx==0 ||
                sy==ty && sx<=tx && (tx-sx)%sy==0;
    }


    bool reachingPoints(int sx, int sy, int tx, int ty) {
        return solve1(sx, sy, tx,ty);
    }
};