import turtle
n = 2
size = 50*n
def koch_curve(t, order, size):
    if order == 1:
        t.forward(size)
    else:
        for angle in [60, -120, 60, 0]:
            koch_curve(t, order-1, size/3)
            t.left(angle)

screen = turtle.Screen()
screen.setup(900, 700)

t = turtle.Turtle()
t.speed(0)


t.up()
t.goto(-150, 150)
t.down()
turtle.tracer(n/2)
for _ in range(4):
    koch_curve(t, n, size)
    t.right(90)

turtle.mainloop()