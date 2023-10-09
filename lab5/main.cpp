#include <iostream>
#include <math.h>

using namespace std;

class figure
{
    protected:
        int x;
        int y;
    
    public:
        int get_x()
        {
            return x;
        }

        int get_y()
        {
            return y;
        }

        figure init_random_figure()
        {
            srand(time(nullptr));

            x = rand() % 10;
            y = rand() % 10;
        }

        figure init_set_figure(int x1,int y1)
        {
            x = x1;
            y = y1;
        }        
};

class line:public figure
{
    protected:
        int x1;
        int y1;
        int length;

    public:
        line init_random_line()
        {
            srand(time(nullptr));

            x = rand() % 10;
            y = y1 = rand() % 10;
            x1 = rand() % 10;
        }

        line init_set_line(int x2,int y2,int x3)
        {
            x = x2;
            y = y1 = y2;
            x1 = x3; 
        }

        void calculation_line()
        {
            length = sqrt(pow(x1 - x,2) + pow(y1 - y,2));
        }
        
        int get_length()
        {
            return length;
        }
};

class square:public line
{
    public:
        square init_random_square()
        {
            srand(time(nullptr));

            init_random_figure();

            x1 = x;
            y1 = y;

            init_random_figure();

            if(x == x1)
                while(x == x1)
                    x1 = rand() % 10;
        }

        square init_set_square()
        {
            cout << "x1 -> ";
            cin >> x;
            cout << "y1 -> ";
            cin >> y;
            cout << "x2 -> ";
            cin >> x1;
            cout << "y2 -> ";
            cin >> y1;

            // if(x != x1)
            //     if(y != y1)
            //         cout << "Error arguments";

            // if(x == x1 && y == y1)
            //     cout << "Error arguments";
        }

        int square_P()
        {
            calculation_line();

            return length * 4;
        }

        int square_S()
        {
            calculation_line();

            return length * length;
        }
};

class rectangle:public square
{
    private:
        int x2;
        int y2;

    public:
        rectangle init_random_rectangle()
        {
            srand(time(nullptr));

            init_random_square();

            if(x > x1)
                x2 = x1;
            else
                x2 = x;

            y2 = rand() % 10;

            if(y2 == y1)
                while(y2 == y1)
                  y2 = rand() % 10;  
        }

        rectangle init_set_rectangle()
        {
            init_set_square();

            cout << "x3 -> ";
            cin >> x2;
            cout << "y3 -> ";
            cin >> y2;

            // if(x != x2)
            //     if(x1 != x2)
            //         cout << "Error arguments";

            // if(y != y2)
            //     if(y1 != y2)
            //         cout << "Error arguments";

            // if(x == x2 && x1 == x2)
            //     cout << "Error arguments";

            // if(y == y2 && y1 == y2)
            //     cout << "Error arguments";
        }

        int rectangle_perimeter()
        {
            calculation_line();

            int section1 = length;

            x1 = x2;
            y1 = y2;

            calculation_line();

            int section2 = length;

            return (section1 + section2) * 2;
        }

        int rectangle_square()
        {
            calculation_line();

            int section1 = length;

            x1 = x2;
            y1 = y2;

            calculation_line();

            int section2 = length;

            return section1 * section2;
        }
};

class circle:public figure
{
    private:
        float R;

    public:
        float get_R()
        {
            return R;
        }

        circle init_random_circle()
        {
            srand(time(nullptr));

            x = rand() % 10;
            y = rand() % 10;
            R = rand() % 10;
        }

        circle init_set_circle(int x1,int y1,float r)
        {
            init_set_figure(x1,y1);

            R = r;
        }

        float circle_perimeter()
        {
            return 2.0 * M_PI * R; 
        }

        float circle_square()
        {
            return M_PI * R * R;
        }
};

class ellipse:public circle
{
    private:
        int x1;
        int y1;

    public:
        ellipse init_random_ellipse()
        {
            srand(time(nullptr));

            x = y1 = 0;

            x1 = rand() % 10;
            y = rand() % 10;
        }

        ellipse init_set_ellipse(int x2,int y2)
        {
            x = y1 = 0;
            x1 = x2;
            y = y2;
        }

        int perimeter_ellipse()
        {
            return 2 * M_PI * sqrt(pow(x1,2) + pow(y,2)/2);
        }
};

int main()
{
    line figureLine,figureLine2;
    square figureSquare,figureSquare2;
    rectangle figureRectangle,figureRectangle2;
    circle figureCircle,figureCircle2;
    ellipse figureEllipse,figureEllipse2;

    figureLine.init_random_line();
    figureLine2.init_set_line(2,5,10);

    cout << "square\n";

    figureSquare.init_random_square();
    figureSquare2.init_set_square();

    cout << "rectangle\n";

    figureRectangle.init_random_rectangle();
    figureRectangle2.init_set_rectangle();
    figureCircle.init_random_circle();
    figureCircle2.init_set_circle(5,5,4);
    figureEllipse.init_random_ellipse();
    figureEllipse2.init_set_ellipse(9,6);

    figureLine.calculation_line();
    figureLine2.calculation_line();

    cout << "length random -> " << figureLine.get_length() << '\n';
    cout << "length set -> " << figureLine2.get_length() << '\n';
    cout << "perimeter random square -> " << figureSquare.square_P() << '\n';
    cout << "perimeter set square -> " << figureSquare2.square_P() << '\n';
    cout << "S random square -> " << figureSquare.square_S() << '\n';
    cout << "S set square -> " << figureSquare2.square_S() << '\n';
    cout << "perimeter random ellipse -> " << figureEllipse.perimeter_ellipse() << '\n';
    cout << "perimeter set ellipse -> " << figureEllipse2.perimeter_ellipse() << '\n';

    cout << "rectangle in array\n";

    rectangle rect1,rect2,rect3;

    rectangle *arr = (rectangle *)malloc(sizeof(rect1) * 3);

    arr[0] = rect1;
    arr[1] = rect2;
    arr[2] = rect3;

    for(int n = 0;n < 3;n++)
        arr[n].init_random_rectangle();

    for(int n = 0;n < 3;n++)
        cout << "P rect" << n + 1 << ' ' << arr[n].rectangle_perimeter() << '\n';

    for(int n = 0;n < 3;n++)
        cout << "S rect" << n + 1 << ' ' << arr[n].rectangle_square() << '\n';

    free(arr);

    return 0;
}