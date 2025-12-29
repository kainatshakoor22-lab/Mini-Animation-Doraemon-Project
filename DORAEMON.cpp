#include <graphics.h>
#include <conio.h>
#include <cmath>  // for sin, cos

int main() {
    initwindow(800, 800, "Doraemon Flying with Bamboo Helicopter");

    float angle = 0;
    int yOffset = 0;

    // Use page flipping for NO BLINKING animation
    int page = 0;

    while (!kbhit()) {
        setactivepage(page);     // Draw on hidden page
        setvisualpage(1 - page); // Show previous frame
        cleardevice();           // Clear only hidden page

        // ===== BACKGROUND (Light Red Sky) =====
        setfillstyle(SOLID_FILL, LIGHTRED);
        bar(0, 0, 800, 800);

        // Face Outline
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        circle(400, 400 - yOffset, 150);
        floodfill(400, 400 - yOffset, BLUE);

        // Face (White)
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        ellipse(400, 430 - yOffset, 0, 360, 120, 100);
        floodfill(400, 430 - yOffset, WHITE);

        // Eyes
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, WHITE);
        circle(370, 330 - yOffset, 30);
        floodfill(370, 330 - yOffset, BLACK);
        circle(430, 330 - yOffset, 30);
        floodfill(430, 330 - yOffset, BLACK);

        // Pupils
        setfillstyle(SOLID_FILL, BLACK);
        circle(370, 330 - yOffset, 8);
        floodfill(370, 330 - yOffset, BLACK);
        circle(430, 330 - yOffset, 8);
        floodfill(430, 330 - yOffset, BLACK);

        // Nose
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(400, 355 - yOffset, 12);
        floodfill(400, 355 - yOffset, RED);

        // Mouth
        setcolor(RED);
        arc(400, 400 - yOffset, 210, 330, 80);
        line(400, 367 - yOffset, 400, 470 - yOffset);

        // Whiskers
        line(300, 390 - yOffset, 360, 380 - yOffset);
        line(300, 410 - yOffset, 360, 400 - yOffset);
        line(300, 430 - yOffset, 360, 420 - yOffset);
        line(440, 380 - yOffset, 500, 390 - yOffset);
        line(440, 400 - yOffset, 500, 410 - yOffset);
        line(440, 420 - yOffset, 500, 430 - yOffset);

        // Bell
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(400, 520 - yOffset, 20);
        floodfill(400, 520 - yOffset, YELLOW);
        setcolor(BLACK);
        line(380, 515 - yOffset, 420, 515 - yOffset);
        circle(400, 525 - yOffset, 5);

        // Body
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        rectangle(330, 520 - yOffset, 470, 650 - yOffset);
        floodfill(400, 600 - yOffset, BLUE);

        // Pocket
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        ellipse(400, 570 - yOffset, 180, 360, 50, 30);
        line(350, 570 - yOffset, 450, 570 - yOffset);
        floodfill(400, 580 - yOffset, WHITE);

        // Hands
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        circle(300, 520 - yOffset, 30);
        floodfill(300, 520 - yOffset, WHITE);
        circle(500, 520 - yOffset, 30);
        floodfill(500, 520 - yOffset, WHITE);

        // Feet
        circle(340, 660 - yOffset, 30);
        floodfill(340, 660 - yOffset, WHITE);
        circle(460, 660 - yOffset, 30);
        floodfill(460, 660 - yOffset, WHITE);

        // ===== Bamboo Helicopter =====
        int centerX = 400;
        int topY = 250 - yOffset;

        // Stick
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        rectangle(centerX - 3, topY, centerX + 3, topY + 30);
        floodfill(centerX, topY + 5, YELLOW);

        // Rotating Blades
        int radius = 60;
        int x1 = centerX + radius * cos(angle);
        int y1 = topY + radius * sin(angle);
        int x2 = centerX - radius * cos(angle);
        int y2 = topY - radius * sin(angle);
        setcolor(BLACK);
        setlinestyle(SOLID_LINE, 0, 3);
        line(x1, y1, x2, y2);

        // ===== Animation Motion =====
        angle += 0.25; // blade rotation speed
        if (angle > 6.28) angle = 0;

        // ? Doraemon flies upward slowly
        if (yOffset < 300)  // limit flying height
            yOffset += 2;

        delay(30); // control animation speed

        page = 1 - page; // swap pages for smooth display
    }

    closegraph();
    return 0;
}
