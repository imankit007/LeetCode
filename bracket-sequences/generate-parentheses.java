class Solution {
    List<String> s = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        s.clear();
        generate(n,0,"");
        return s;
        
        
    }
    
    public void generate(int n, int count, String p){
        if(n==0 && count ==0){
            s.add(p);
            return;
        }
        
        if(n==0){
            generate(n,count-1,p+")");
        }else if(count==0){
            generate(n-1,count+1,p+"(");
        }else{
            generate(n,count-1,p+")");
            generate(n-1,count+1,p+"(");
        }
        
    }
}