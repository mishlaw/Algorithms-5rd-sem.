import turtle
import turtle as tur
n=2
h=15
tur.up()
tur.goto(n*80, n*80)
tur.down()
x=n*80
y=n*80

#Кол-во отрезков для n?
def A(n):
    global x, y
    if n>0:
        D(n-1)
        x-=h
        tur.goto(x, y)
        A(n-1)
        y-=h
        tur.goto(x, y)
        A(n-1)
        x+=h
        tur.goto(x, y)
        B(n-1)

def B(n):
    global x, y
    if n>0:
        C(n-1)
        y+=h
        tur.goto(x, y)
        B(n-1)
        x+=h
        tur.goto(x, y)
        B(n-1)
        y-=h
        tur.goto(x,y)
        A(n-1)

def C(n):
    global x, y
    if n>0:
        B(n-1)
        x+=h
        tur.goto(x,y)
        C(n-1)
        y+=h
        tur.goto(x, y)
        C(n-1)
        x-=h
        tur.goto(x, y)
        D(n-1)

def D(n):
    global x, y
    if n>0:
        A(n-1)
        y-=h
        tur.goto(x, y)
        D(n-1)
        x-=h
        tur.goto(x, y)
        D(n-1)
        y+=h
        tur.goto(x, y)
        C(n-1)

turtle.speed(0)
screen = tur.Screen()
screen.setup(900, 700)
turtle.tracer(n/2)
A(n)

tur.mainloop()