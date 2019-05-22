#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
GLfloat s = 0.0f;
GLfloat m=0.0f;
GLfloat h=0.0f;
#define PI acos(-1)
void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); /// white
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f); /// Black

}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void calculate_time()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    s=-(int) ( (timePtr->tm_sec)*6+2*6 ); //+2 for late display
    m=- (int)( (timePtr->tm_min)*6 );
    h=-(int) ( (timePtr->tm_hour)*30 - ( (int)(m/72) )*6 )   ;



   // cout << "h : " << h << " m : " << m << " s : " << s << endl;
//
//  cout << "seconds= " << (timePtr->tm_sec) << endl;
//  cout << "minutes = " << (timePtr->tm_min) << endl;
//  cout << "hours = " << (timePtr->tm_hour) << endl;
//  cout << "day of month = " << (timePtr->tm_mday) << endl;
//  cout << "month of year = " << (timePtr->tm_mon)+1 << endl;
//  cout << "year = " << (timePtr->tm_year)+1900 << endl;
//  cout << "weekday = " << (timePtr->tm_wday )<< endl;
//  cout << "day of year = " << (timePtr->tm_yday )<< endl;
//  cout << "daylight savings = " <<(timePtr->tm_isdst )<< endl;
//  cout << endl;
//  cout << endl;
//
//
//  cout << "Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
  //cout << "Time     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
}
void DrawQuad()
{
    ///quad
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0.6, -0.6);
    glVertex2f( 0.6f, 0.6f);
    glVertex2f(-0.6, 0.6);
    glVertex2f( -0.6f, -0.6f);
    glEnd();
}
void DrawCircleFan(GLfloat radius)
{
    glColor3ub(255,255,255);///white
    //glColor3ub(0,0,0);///black

    GLfloat centerX=.0f; GLfloat centerY=.0f;
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    centerX + (radius * cos(i *  twicePi / lineAmount)),
			    centerY + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

}
void DrawCircle(GLfloat radius)
{
    GLfloat centerX=.0f; GLfloat centerY=.0f;
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    centerX + (radius * cos(i *  twicePi / lineAmount)),
			    centerY + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

}

void DrawNumberingLine(GLfloat radius)
{
    //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    for(int i=0;i<=360;i+=6)
    {
        glPushMatrix();
        glRotatef(i,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis

		glColor3ub(0,0,255);
		if(i%30==0)
        {
            glBegin(GL_QUADS);
            glVertex2d(0.007,-0.07);
            glVertex2d(0.007,radius);
            glVertex2d(-0.007,radius);
            glVertex2d(-0.007,-0.07);
            glEnd();


        }
		else
        {
            glBegin(GL_QUADS);
            glVertex2d(0.002,-0.07);
            glVertex2d(0.002,radius);
            glVertex2d(-0.002,radius);
            glVertex2d(-0.002,-0.07);
            glEnd();

        }
		glPopMatrix();
    }
}
void display()
{
    //cout << "display \n";
    //cout << "h : " << h << " m : " << m << " s : " << s << endl;
	Sleep(1000);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();//Reset the current matrix

	//DrawQuad();

    DrawNumberingLine(0.6f);
    DrawCircleFan(0.5f);
    //DrawCircle(0.7f);


    ///second
    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glRotatef(s,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis
    glTranslatef(0.f,0.0f,0.f);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2d(0.003,-0.1);
    glVertex2d(0.003,0.5);
    glVertex2d(-0.003,0.5);
    glVertex2d(-0.003,-0.1);
    glEnd();
    glPopMatrix();

	///minute
    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glRotatef(m,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(0.007,-0.07);
    glVertex2d(0.007,0.4);
    glVertex2d(-0.007,0.4);
    glVertex2d(-0.007,-0.07);
    glEnd();
    glPopMatrix();



    ///hour
    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glRotatef(h,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2d(0.007,-0.07);
    glVertex2d(0.007,0.3);
    glVertex2d(-0.007,0.3);
    glVertex2d(-0.007,-0.07);
    glEnd();

    glPopMatrix();




    s-=6.0f;
	if(s==-360)
	{
		s=0;
		m-=6;

        if( ((int)m)%72==0)
        {
            h-=6;
            if(h==-360) h=0;
        }
        if(m==-360) m=0;
	}


    glFlush();
}

int main(int argc, char** argv)
{
    calculate_time();
    glutInit(&argc, argv);          // Initialize GLUT
    cout << "if window doesn't fit then change it in line 219";
    glutInitWindowSize(1200, 700);
    glutCreateWindow("Model Transform");
    glutDisplayFunc(display);//
    initGL();
    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.
    glutMainLoop();
    return 0;
}
