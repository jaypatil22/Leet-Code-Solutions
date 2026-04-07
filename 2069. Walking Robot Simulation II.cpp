class Robot {
public:
    int width, height,steps;
    string direction;
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->direction = "East";
        this->steps = 0;
    }
    
    void step(int num) {
        this->steps += num;
        return;
    }
    
    vector<int> getPos() {
        int round = (2*width)+(2*height)-4;
        int r_steps = steps%round;
        if(r_steps < width) {
            return {r_steps, 0};
        }
        r_steps -= (width-1);
        if(r_steps < height) {
            return {width-1, r_steps};
        }
        r_steps -= (height-1);
        if(r_steps < width) {
            return{(width-1)-r_steps, height-1};
        }
        r_steps -= width-1;
        return {0, (height-1)-r_steps};
    }
    
    string getDir() {
        int round = (2*width)+(2*height)-4;
        int r_steps = steps%round;
        if(steps>0 and r_steps == 0) return "South";
        if(r_steps < width) {
            return "East";
        }
        r_steps -= (width-1);
        if(r_steps < height) {
            return "North";
        }
        r_steps -= (height-1);
        if(r_steps < width) {
            return "West";
        }
        r_steps -= width-1;
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */