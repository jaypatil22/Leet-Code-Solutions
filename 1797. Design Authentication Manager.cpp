class AuthenticationManager
{
public:
    int timeToLive;
    map<string, int> tokens;
    AuthenticationManager(int timeToLive)
    {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        tokens[tokenId] = currentTime + this->timeToLive;
    }

    void renew(string tokenId, int currentTime)
    {
        if (tokens.find(tokenId) == tokens.end() || tokens[tokenId] <= currentTime)
        {
        }
        else
        {
            tokens[tokenId] = currentTime + this->timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime)
    {
        int res = 0;
        for (auto token : tokens)
        {
            if (token.second > currentTime)
            {
                res++;
            }
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */