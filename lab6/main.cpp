#include <iostream>
#include <math.h>

using namespace std;

class figure
{
    protected:
        int x = -2147483648;
        int y = -2147483648;
    
    public:
        virtual void init_random() = 0;

        virtual void init_set() = 0;

        virtual void free_figure() = 0;
};

class line:public figure
{
    protected:
        int x1 = -2147483647;
        int y1 = -2147483647;
        int length;

    public:
        static inline int count_object_line_init = 0;
        static inline int count_object_line_existing = 0;

        void init_random() override
        {
            count_object_line_init++;

            srand(time(nullptr));

            x = rand() % 10;
            y = rand() % 10;
            x1 = rand() % 10;
            y = y1;
        }

        void init_set() override
        {
            count_object_line_init++;

            cout << "x1 -> ";
            cin >> x;
            cout << "y1 -> ";
            cin >> y;
            cout << "x2 -> ";
            cin >> x1;

            y = y1;
        }

        void calculation_line()
        {
            length = sqrt(pow(x1 - x,2) + pow(y1 - y,2));
        }
        
        int get_length()
        {
            return length;
        }

        void check_object_line(line lin)
        {
            if(lin.y1 == lin.y){
                lin.count_object_line_existing++;
            }else if(lin.x == -2147483645){
                lin.count_object_line_init--;
            }
        }

        void free_figure() override
        {
            x = -2147483645;
            y = -2147483645;
            x1 = -2147483645;
            y1 = -2147483645;
        }
};

class square:public line
{
    public:
        static inline int count_object_square_init = 0;
        static inline int count_object_square_existing = 0;

        void init_random() override
        {
            count_object_square_init++;

            srand(time(nullptr));

            x = rand() % 10;
            y = rand() % 10;
            x1 = rand() % 10;
            y1 = y;

            if(x == x1)
                while(x == x1)
                    x1 = rand() % 10;
        }

        void init_set() override
        {
            count_object_square_init++;

            cout << "x1 -> ";
            cin >> x;
            cout << "y1 -> ";
            cin >> y;
            cout << "x2 -> ";
            cin >> x1;
            
            y1 = y;
        }

        virtual int Perimeter()
        {
            calculation_line();

            return length * 4;
        }

        virtual int Square()
        {
            calculation_line();

            return length * length;
        }

        void check_object_square(square squa)
        {
            if(squa.y == squa.y1){
                squa.count_object_square_existing++;
            }else if(squa.x == -2147483645){
                squa.count_object_square_init--;
            }
        }

        void free_figure() override
        {
            x = -2147483645;
            y = -2147483645;
            x1 = -2147483645;
            y1 = -2147483645;
        }
};

class rectangle:public square
{
    private:
        int x2 = -2147483646;
        int y2 = -2147483646;

    public:
        static inline int count_object_rectangle_init = 0;
        static inline int count_object_rectangle_existing = 0;

        void init_random() override
        {
            count_object_rectangle_init++;

            srand(time(nullptr));

            x = rand() % 10;
            y = rand() % 10;
            x1 = rand() % 10;

            y1 = y;
            x2 = x;

            y2 = rand() % 10;

            if(y2 == y1)
                while(y2 == y1)
                  y2 = rand() % 10;  
        }

        void init_set() override
        {
            count_object_rectangle_init++;

            cout << "x1 -> ";
            cin >> x;
            cout << "y1 -> ";
            cin >> y;
            cout << "x2 -> ";
            cin >> x1;
            cout << "y3 -> ";
            cin >> y2;

            y1 = y;
            x2 = x;
        }

        int Perimeter() override
        {
            calculation_line();

            int section1 = length;

            x1 = x2;
            y1 = y2;

            calculation_line();

            int section2 = length;

            return (section1 + section2) * 2;
        }

        int Square() override
        {
            calculation_line();

            int section1 = length;

            x1 = x2;
            y1 = y2;

            calculation_line();

            int section2 = length;

            return section1 * section2;
        }

        void check_object_rectangle(rectangle rect)
        {
            if(rect.x2 == rect.x && rect.y == rect.y1){
                rect.count_object_rectangle_existing++;
            }else if(rect.x == -2147483645){
                rect.count_object_rectangle_init--;
            }
        }

        void free_figure() override
        {
            x = -2147483645;
            y = -2147483645;
            x1 = -2147483645;
            y1 = -2147483645;
            x2 = -2147483645;
            y2 = -2147483645;
        }
};

class circle:public figure
{
    private:
        float R;

    public:
        static inline int count_object_circle_init = 0;
        static inline int count_object_circle_existing = 0;

        float get_R()
        {
            return R;
        }

        void init_random() override
        {
            count_object_circle_init++;

            srand(time(nullptr));

            x = rand() % 10;
            y = rand() % 10;
            R = rand() % 10;
        }

        void init_set() override
        {
            count_object_circle_init++;

            cout << "x1 -> ";
            cin >> x;
            cout << "y1 -> ";
            cin >> y;
            cout << "R -> ";
            cin >> R;

            if(R < 0)
                R *= -1;
        }

        virtual float Perimeter()
        {
            return 2.0 * M_PI * R; 
        }

        float circle_square()
        {
            return M_PI * R * R;
        }

        void check_object_circle(circle circ)
        { 
            if(circ.R > 0)
                circ.count_object_circle_existing++;
        }

        void free_figure() override
        {
            x = -2147483645;
            y = -2147483645;
        }
};

class ellipse:public circle
{
    private:
        int x1 = -2147483645;
        int y1 = -2147483645;

    public:
        static inline int count_object_ellipse_init = 0;
        static inline int count_object_ellipse_existing = 0;

        void init_random() override
        {
            count_object_ellipse_init++;

            srand(time(nullptr));

            x = y1 = 0;

            x1 = rand() % 10;
            y = rand() % 10;
        }

        void init_set() override
        {
            count_object_ellipse_init++;

            x = y1 = 0;

            cout << "x2 -> ";
            cin >> x1;
            cout << "y1 -> ";
            cin >> y;
        }

        float Perimeter() override
        {
            return 2.0 * M_PI * sqrt(pow(x1,2) + pow(y,2) / 2.0);
        }

        void check_object_ellipse(ellipse elli)
        {
            if(elli.x == 0 && elli.y1 == 0){
                elli.count_object_ellipse_existing++;
            }else if(elli.x == -2147483644){
                elli.count_object_ellipse_init--;
            }
        }

        void free_figure() override
        {
            x = -2147483644;
            y = -2147483644;
            x1 = -2147483644;
            y1 = -2147483644;
        }
};

int main()
{
    line figureLine,figureLine2;
    square figureSquare,figureSquare2;
    rectangle figureRectangle,figureRectangle2;
    circle figureCircle,figureCircle2;
    ellipse figureEllipse,figureEllipse2;

    cout << "line\n";

    figureLine.init_random();
    figureLine2.init_set();

    cout << "square\n";

    figureSquare.init_random();
    figureSquare2.init_set();

    cout << "rectangle\n";

    figureRectangle.init_random();
    figureRectangle2.init_set();

    cout << "circle\n";

    figureCircle.init_random();
    figureCircle2.init_set();

    cout << "ellipse\n";

    figureEllipse.init_random();
    figureEllipse2.init_set();
    figureRectangle.check_object_rectangle(figureRectangle);
    figureRectangle2.check_object_rectangle(figureRectangle2);

    cout << "count rectangle init -> " << figureRectangle.count_object_rectangle_init << '\n';
    cout << "count rectangle existing -> " << figureRectangle.count_object_rectangle_existing << '\n';
    cout << "count rectangle init -> " << figureRectangle2.count_object_rectangle_init << '\n';
    cout << "count rectangle existing -> " << figureRectangle2.count_object_rectangle_existing << '\n';

    rectangle *figureRectangle3 = (rectangle *)malloc(sizeof(figureRectangle3));

    figureRectangle3->check_object_rectangle(*figureRectangle3);

    cout << "count rectangle init -> " << figureRectangle3->count_object_rectangle_init << '\n';
    cout << "count rectangle existing -> " << figureRectangle3->count_object_rectangle_existing << '\n';

    rectangle *figureRectangle4 = (rectangle *)malloc(sizeof(figureRectangle4));

    figureRectangle4->check_object_rectangle(*figureRectangle4);

    cout << "count rectangle init -> " << figureRectangle4->count_object_rectangle_init << '\n';
    cout << "count rectangle existing -> " << figureRectangle4->count_object_rectangle_existing << '\n';

    ellipse figureEllipse3,figureEllipse4;
    rectangle figureRectangle5,figureRectangle6;

    rectangle *arr = (rectangle *)malloc(sizeof(rectangle*) * 2);

    arr = (rectangle *)malloc(sizeof(rectangle));
    arr++;
    arr = (rectangle *)malloc(sizeof(rectangle));

    arr[0] = figureRectangle5;
    arr[1] = figureRectangle6;

    arr[1].check_object_rectangle(arr[1]);

    ellipse *arr2 = (ellipse *)malloc(sizeof(ellipse*) * 2);

    arr2 = (ellipse *)malloc(sizeof(ellipse));
    arr2++;
    arr2 = (ellipse *)malloc(sizeof(ellipse));

    arr2[0] = figureEllipse3;
    arr2[1] = figureEllipse4;

    figureRectangle5.init_random();
    figureRectangle6.init_random();
    figureEllipse3.init_random();
    figureEllipse4.init_random();

    cout << "arr[0] -> " << figureRectangle5.Perimeter() << '\n';
    cout << "arr[0] -> " << figureRectangle5.Square() << '\n';
    cout << "arr[1] -> " << figureRectangle6.Perimeter() << '\n';
    cout << "arr[1] -> " << figureRectangle6.Square() << '\n';
    cout << "arr2[0] -> " << figureEllipse3.Perimeter() << '\n';
    cout << "arr2[0] -> " << figureEllipse3.Perimeter() << '\n';

    figureRectangle5.check_object_rectangle(figureRectangle5);
    figureRectangle6.check_object_rectangle(figureRectangle6);

    cout << "count rectangle init -> " << figureRectangle5.count_object_rectangle_init << '\n';
    cout << "count rectangle existing -> " << figureRectangle5.count_object_rectangle_existing << '\n';
    cout << "count rectangle init -> " << figureRectangle6.count_object_rectangle_init << '\n';
    cout << "count rectangle existing -> " << figureRectangle6.count_object_rectangle_existing << '\n';

    free(arr);
    free(arr2);

    figureRectangle5.free_figure();
    figureRectangle6.free_figure();

    figureRectangle5.check_object_rectangle(figureRectangle5);
    figureRectangle6.check_object_rectangle(figureRectangle6);

    cout << "count rectangle init -> " << figureRectangle5.count_object_rectangle_init << '\n';
    cout << "count rectangle existing -> " << figureRectangle5.count_object_rectangle_existing << '\n';
    cout << "count rectangle init -> " << figureRectangle6.count_object_rectangle_init << '\n';
    cout << "count rectangle existing -> " << figureRectangle6.count_object_rectangle_existing << '\n';

    return 0;
}