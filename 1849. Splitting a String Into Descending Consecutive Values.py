class Solution:
    def splitString(self, s: str) -> bool:
        n = len(s)
        
        def helper(start,e) :
            if start == n:
                return True
            
            for i in range(start+1,n+1-(start==0)):
                val = int(s[start:i])
                
                if e==None or val==e:
                    if helper(i,val-1) :
                        return True
            return False
        return helper(0,None)