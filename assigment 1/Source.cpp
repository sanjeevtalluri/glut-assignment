
#include <GL\glut.h>
 GLfloat xRotated, yRotated, zRotated;
 GLfloat xscale, yscale, zscale,r,g,b;
 GLint view_mode=0;
 GLint vx, vy;

 static int menu_id;
void init(void)
{
glClearColor(1,1,1,0);
xscale=1;
yscale=1;zscale=1;
r=0,g=1,b=0;

/*gluLookAt(camera[0], camera[1], camera[2], /* look from camera XYZ */ 
         // 0, 0, 0,i  /* look at the origin */ 
        (  0, 1, 0); /* positive Y up vector */

 
}

void DrawCube(void)
{

     glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
    glTranslatef(0.0,0.0,-10.5);
	//glTranslatef(1.0,2.0,-8.5);
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
	glScalef(xscale,yscale,zscale);
    glRotatef(zRotated,0.0,0.0,1.0);
  glBegin(GL_QUADS);        // Draw The Cube Using quads
    glColor3f(r,g,b);    // Color Blue
	//glColor3f(0.0f,1.0f,0.0f); 
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
   // glColor3f(1.0f,0.5f,0.0f);    // Color Orange
	glColor3f(r,g,b); 
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
    //glColor3f(1.0f,0.0f,0.0f);    // Color Red  
	glColor3f(r,g,b); 
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
    //glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
	glColor3f(r,g,b); 
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
    //glColor3f(0.0f,0.0f,1.0f);  // Color Blue
	glColor3f(r,g,b); 
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
    //glColor3f(1.0f,0.0f,1.0f);    // Color Violet
	glColor3f(r,g,b); 
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)vv
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)
  glEnd();            // End Drawing The Cube
glFlush();
}
    


void animation(void)
{
 
  //  yRotated += 0.01;
  //   xRotated += 0.02;
    DrawCube();
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
	vx = x;
	vy =y;
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
	if(view_mode==1){
	  gluPerspective(80.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
	 }else{
	glOrtho(-2,2,-2,2,5,80);
	}
    
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}
void processNormalKeys(unsigned char key, int x, int y) {

	if(key=='i'){
		if(view_mode==0){
			view_mode=1;

	}else if(view_mode==1)
		{view_mode=0;}
	}

	if (key == 27)
		exit(0);
	else if (key=='r') {
		yRotated += 30;

	}
	
	else if (key=='q') {
		zRotated += 20;}
	
	else if (key=='w') {
		xRotated += 10;
	}
	else if (key=='m'){//i changed the key to m
		xscale++;
	yscale++;
	zscale++;
	}
	reshape(vx, vy);
}
void menu(int a)
{
	if(a==2)
	{
		r=0,g=0,b=1;
	}

	if (a==1)
	{
		r=1,g=0,b=0;
	}
	glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{

}




int main(int argc, char** argv){

glutInit(&argc, argv);
//we initizlilze the glut. functions
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100, 100);
glutCreateWindow(argv[0]);
init();
glutCreateMenu(menu);
glutAddMenuEntry("red",1);
glutAddMenuEntry("blue",2);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMouseFunc(mouse);


glutDisplayFunc(DrawCube);
glutReshapeFunc(reshape);
glutKeyboardFunc(processNormalKeys);
//Set the function for the animation.
glutIdleFunc(animation);
glutMainLoop();
return 0;
}
 