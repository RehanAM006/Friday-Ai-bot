#include <Servo.h>

Servo head;
//right_hand
Servo rh1; 
Servo rh2; 
Servo rh3;
//right_leg
Servo rl1;
Servo rl2;
Servo rl3;
Servo rl4;
Servo rl5;
//left_hand
Servo lh1;
Servo lh2;
Servo lh3;
Servo ll1;
//left_leg
Servo ll2;
Servo ll3;
Servo ll4;
Servo ll5;


byte val = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("GPIO test!");

  head.attach(2);
  rh1.attach(3); //rt shoulder
  rh2.attach(4); // rt elbow
  rh3.attach(5); // rt bns
  rl1.attach(6); //rt abd
  rl2.attach(7); // rt thigh
  rl3.attach(8); // rt femur up
  rl4.attach(9); //rt femur down
  rl5.attach(10); //rt foot
  lh1.attach(11); //left shoulder
  lh2.attach(12); 
  lh3.attach(13);
  ll1.attach(A0); //left abd
  ll2.attach(A1); //left thigh
  ll3.attach(A2); //left femur up
  ll4.attach(A3); //left femur down
  ll5.attach(A4); //left foot
  stand_straight();
}

void loop() {
  while (Serial.available() > 0) {
    delay(10);
    val = Serial.read();
  }

  if (val > 0) {
    Serial.println(val);
    if (val == "t") {
      stand_straight();
    }
    if (val == "h") {
      say_hi();
    }
    if (val == "s") {
      shake_hand();
    }
    if (val == "u") {
      hands_up();
    }
    if (val == "d") {
      hands_down();
    }
    if (val == "q") {
      right_bicep();
    }
    if (val == "w") {
      left_bicep();
    }
    if (val == "e") {
      double_biceps();
    }
    if (val == "r") {
      maan_karate();
    }
    if (val == "y") {
      do_bow();
    }
    if (val == "i") {
      ape_move();
    }
    if (val == "o") {
      exercise_one();
    }
    if (val == "p") {
      side_bend();
    }
    if (val == "a") {
      sit_down();
    }
    if (val == "f") {
      stand_up();
    }
    if (val == "g") {
      do_dab();
    }
    if (val == "j") {
      move_forward();
    }
    if (val == "k") {
      turn_left();
    }
    if (val == "l") {
      turn_right();
    }
    if (val == "z") {
      push_ups();
    }
    if (val == "x") {
      gangnam_style_dance();
    }
    if (val == "c") {
      dance_steps();
    }
  }
  val = "";


}

void stand_straight() {
  head.write(90);
  rh1.write(0);
  rh2.write(0);
  rh3.write(20);
  rl1.write(90);
  rl2.write(150);
  rl3.write(30);
  rl4.write(30);
  rl5.write(90);

  lh1.write(180);
  lh2.write(180);
  lh3.write(160);
  ll1.write(90);
  ll2.write(30);
  ll3.write(150);
  ll4.write(150);
  ll5.write(90);
}
//********************say hi********************//
void say_hi() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(0 + i);
    if (i <= 90) {
      rh2.write(0 + i);
    }
    if (i <= 40) {
      rh3.write(20 + i);
    }
    delay(15);
  }
  for (int i = 1; i <= 3; i++) {
    for (int i = 0; i <= 60; i++) {
      rh3.write(60 + i);
      delay(15);
    }
    for (int i = 0; i <= 60; i++) {
      rh3.write(120 - i);
      delay(15);
    }
  }
  for (int i = 0; i <= 180; i++) {
    rh1.write(180 - i);
    if (i <= 90) {
      rh2.write(90 - i);
    }
    if (i <= 40) {
      rh3.write(60 - i);
    }
    delay(15);
  }
}
//********************shake hand********************//
void shake_hand() {
  for (int i = 0; i <= 40; i++) {
    rh1.write(0 + i);
    delay(10);
  }
  for (int i = 0; i <= 3; i++) {
    for (int i = 0; i <= 30; i++) {
      rh1.write(40 + i);
      delay(15);
    }
    for (int i = 0; i <= 30; i++) {
      rh1.write(70 - i);
      delay(15);
    }
  }
  for (int i = 0; i <= 40; i++) {
    rh1.write(40 - i);
    delay(10);
  }
}
//********************hands up********************//
void hands_up() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(0 + i);
    lh1.write(180 - i);
    delay(15);
  }
}
//********************hands down********************//
void hands_down() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(180 - i);
    lh1.write(0 + i);
    delay(15);
  }
}
//********************right bicep********************//
void right_bicep() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(0 + i);
    if (i <= 90) {
      rh2.write(0 + i);
    }
    if (i <= 60) {
      head.write(90 - i);
    }
    delay(15);
  }
  for (int i = 0; i <= 120; i++) {
    rh3.write(20 + i);
    delay(15);
  }
  delay(3000);
  for (int i = 0; i <= 120; i++) {
    rh3.write(140 - i);
    delay(15);
  }
  for (int i = 0; i <= 180; i++) {
    rh1.write(180 - i);
    if (i <= 90) {
      rh2.write(90 - i);
    }
    if (i <= 60) {
      head.write(30 + i);
    }
    delay(15);
  }
}
//********************left bicep********************//
void left_bicep() {
  for (int i = 0; i <= 180; i++) {
    lh1.write(180 - i);
    if (i <= 90) {
      lh2.write(180 - i);
    }
    if (i <= 60) {
      head.write(90 + i);
    }
    delay(15);
  }
  for (int i = 0; i <= 120; i++) {
    lh3.write(160 - i);
    delay(15);
  }
  delay(3000);
  for (int i = 0; i <= 120; i++) {
    lh3.write(40 + i);
    delay(15);
  }
  for (int i = 0; i <= 180; i++) {
    lh1.write(0 + i);
    if (i <= 90) {
      lh2.write(90 + i);
    }
    if (i <= 60) {
      head.write(150 - i);
    }
    delay(15);
  }
}
//********************double biceps********************//
void double_biceps() {
  for (int i = 0; i <= 180; i++) {
    lh1.write(180 - i);
    rh1.write(0 + i);
    if (i <= 90) {
      lh2.write(180 - i);
      rh2.write(0 + i);
    }
    delay(15);
  }
  for (int i = 0; i <= 120; i++) {
    lh3.write(160 - i);
    rh3.write(20 + i);
    delay(15);
  }
  delay(3000);
  for (int i = 0; i <= 120; i++) {
    lh3.write(40 + i);
    rh3.write(140 - i);
    delay(15);
  }
  for (int i = 0; i <= 180; i++) {
    lh1.write(0 + i);
    rh1.write(180 - i);
    if (i <= 90) {
      lh2.write(90 + i);
      rh2.write(90 - i);
    }
    delay(15);
  }
}
//********************do bow********************//
void do_bow() {
  for (int i = 0; i <= 10; i++) {
    ll2.write(30 + (i * 2));
    rl2.write(150 - (i * 2));

    ll4.write(150 + i);
    rl4.write(30 - i);
    delay(100);
  }
  delay(3000);
  for (int i = 0; i <= 10; i++) {
    ll2.write(50 - (i * 2));
    rl2.write(130 + (i * 2));
    ll4.write(160 - i);
    rl4.write(20 + i);
    delay(100);
  }
}
//********************maan karate********************//
void maan_karate() {
  for (int i = 0; i <= 180; i++) {
    if (i <= 90) {
      head.write(90 + i);
    }
    if (i <= 120) {
      lh2.write( 180 - i);
    }
    if (i <= 20) {
      lh3.write( 160 + i);
    }
    rh1.write( 0 + i);
    if (i <= 120) {
      rh2.write( 0 + i);
    }
    if (i <= 130) {
      rh3.write( 20 + i);
    }
    if (i <= 10) {
      rl1.write( 90 - i);
      rl5.write( 90 - i);
    }
    if (i <= 10) {
      rl2.write( 150 - i);
      rl3.write( 30 + i);
      rl4.write( 30 + i);
    }
    delay(15);
  }
  delay(5000);
  for (int i = 0; i <= 180; i++) {
    if (i <= 90) {
      head.write(180 - i);
    }
    if (i <= 120) {
      lh2.write( 60 + i);
    }
    if (i <= 20) {
      lh3.write( 180 - i);
    }
    rh1.write( 180 - i);
    if (i <= 120) {
      rh2.write( 120 - i);
    }
    if (i <= 130) {
      rh3.write( 150 - i);
    }
    if (i <= 10) {
      rl1.write( 80 + i);
      rl5.write( 80 + i);
    }
    if (i <= 10) {
      rl2.write( 140 + i);
      rl3.write( 40 - i);
      rl4.write( 40 - i);
    }
    delay(15);
  }
}
//********************ape move********************//
void ape_move() {
  for (int i = 0; i <= 180; i++) {
    if (i <= 90) {
      lh1.write( 180 - i);
      rh1.write( 0 + i);
    }
    if (i <= 20) {
      lh2.write( 180 - i);
      rh2.write( 0 + i);
    }
    delay(15);
  }
  delay(100);
  for (int i = 0; i <= 100; i++) {
    if (i <= 50) {
      head.write(90 + i);
    }
    lh3.write( 160 - i);
    delay(10);
  }
  for (int i = 1; i <= 3; i++) {
    for (int i = 0; i <= 100; i++) {
      head.write(140 - i);
      rh3.write( 20 + i);
      lh3.write( 60 + i);
      delay(10);
    }
    for (int i = 0; i <= 100; i++) {
      head.write(40 + i);
      rh3.write( 120 - i);
      lh3.write( 160 - i);
      delay(10);
    }
  }
  for (int i = 0; i <= 100; i++) {
    if (i <= 50) {
      head.write(140 - i);
    }
    lh3.write( 60 + i);
    delay(10);
  }
  delay(100);
  for (int i = 0; i <= 180; i++) {
    if (i <= 90) {
      lh1.write( 90 + i);
      rh1.write( 90 - i);
    }
    if (i <= 20) {
      lh2.write( 160 + i);
      rh2.write( 20 - i);
    }
    delay(15);
  }
}
//********************exercise one********************//
void exercise_one() {
  for (int i = 0; i <= 90; i++) {
    rh1.write(0 + i);
    lh1.write(180 - i);
    delay(15);
  }
  delay(2000);
  for (int i = 0; i <= 90; i++) {
    rh1.write(90 + i);
    lh1.write(90 - i);
    delay(15);
  }
  delay(2000);
  for (int i = 0; i <= 90; i++) {
    rh1.write(180 - i);
    lh1.write(0 + i);
    rh2.write(0 + i);
    lh2.write(180 - i);
    delay(15);
  }
  delay(2000);
  for (int i = 0; i <= 90; i++) {
    rh1.write(90 - i);
    lh1.write(90 + i);
    rh2.write(90 - i);
    lh2.write(90 + i);
    delay(15);
  }
  delay(2000);
}
//********************exercise one side bend********************//
void side_bend() {
  //right
  for (int i = 0; i <= 180; i++) {
    rh1.write(0 + i);
    if (i % 4 == 0) {
      lh2.write(180 - i / 4);//135
    }
    if (i % 3 == 0) {
      lh3.write(160 - i / 3);//100
    }
    delay(15);
  }
  for (int i = 0; i <= 60; i++) {
    rh3.write(20 + i);
    if (i % 6 == 0) {
      rl1.write( 90 - i / 6);
      rl5.write( 90 - i / 6);
      ll1.write( 90 - i / 6);
      ll5.write( 90 - i / 6);
    }
    delay(30);
  }
  for (int i = 0; i <= 60; i++) {
    rh3.write(80 - i);
    if (i % 6 == 0) {
      rl1.write( 80 + i / 6);
      rl5.write( 80 + i / 6);
      ll1.write( 80 + i / 6);
      ll5.write( 80 + i / 6);
    }
    delay(30);
  }
  for (int i = 0; i <= 180; i++) {
    rh1.write(180 - i);
    if (i % 4 == 0) {
      lh2.write(135 + i / 4);//135
    }
    if (i % 3 == 0) {
      lh3.write(100 + i / 3);//100
    }
    delay(15);
  }
  delay(1000);
  //left
  for (int i = 0; i <= 180; i++) {
    lh1.write(180 - i);
    if (i % 4 == 0) {
      rh2.write(0 + i / 4);//45
    }
    if (i % 3 == 0) {
      rh3.write(20 + i / 3);//80
    }
    delay(15);
  }
  for (int i = 0; i <= 60; i++) {
    lh3.write(160 - i);
    if (i % 6 == 0) {
      rl1.write( 90 + i / 6);
      rl5.write( 90 + i / 6);
      ll1.write( 90 + i / 6);
      ll5.write( 90 + i / 6);
    }
    delay(30);
  }
  for (int i = 0; i <= 60; i++) {
    lh3.write(100 + i);
    if (i % 6 == 0) {
      rl1.write( 100 - i / 6);
      rl5.write( 100 - i / 6);
      ll1.write( 100 - i / 6);
      ll5.write( 100 - i / 6);
    }
    delay(30);
  }
  for (int i = 0; i <= 180; i++) {
    lh1.write(0 + i);
    if (i % 4 == 0) {
      rh2.write(45 - i / 4);//45
    }
    if (i % 3 == 0) {
      rh3.write(80 - i / 3);//80
    }
    delay(15);
  }
}
//********************sit down********************//
void sit_down() {
  for (int i = 0; i <= 60; i++) {
    if (i <= 30) {
      lh2.write(180 - i);
      rh2.write(0 + i);
      lh1.write(180 - i);
      rh1.write(0 + i);
    }
    if (i % 2 == 0) {
      rh3.write(20 + i / 2);
      lh3.write(160 - i / 2);
    }
    rl2.write(150 - i);
    ll2.write(30 + i);
    rl3.write(30 + (i * 2));
    ll3.write(150 - (i * 2));
    rl4.write(30 + i);
    ll4.write(150 - i);

    delay(100);
  }
}

//********************stand up********************//
void stand_up() {
  for (int i = 0; i <= 60; i++) {
    if (i <= 30) {
      lh2.write(150 + i);
      rh2.write(30 - i);
      lh1.write(150 + i);
      rh1.write(30 - i);
    }
    if (i % 2 == 0) {
      rh3.write(50 - i / 2);
      lh3.write(130 + i / 2);
    }
    rl2.write(90 + i);
    ll2.write(90 - i);
    rl3.write(150 - (i * 2));
    ll3.write(30 + (i * 2));
    rl4.write(90 - i);
    ll4.write(90 + i);
    delay(100);
  }
}
//********************dab********************//
void do_dab() {
  for (int i = 0; i <= 90; i++) {
    lh2.write(180 - i);
    rh1.write(0 + i);
    if (i <= 70) {
      rh3.write(20 + i);
    }
    if (i <= 20) {
      lh3.write(160 + i);
    }
    if (i % 10 == 0) {
      rl2.write(150 - (i / 10));
      ll2.write(30 + (i / 10));
    }
    delay(15);
  }
  delay(5000);
  for (int i = 0; i <= 90; i++) {
    lh2.write(90 + i);
    rh1.write(90 - i);
    if (i <= 70) {
      rh3.write(90 - i);
    }
    if (i <= 20) {
      lh3.write(180 - i);
    }
    if (i % 10 == 0) {
      rl2.write(141 + (i / 10));
      ll2.write(39 - (i / 10));
    }
    delay(15);
  }
}
//********************move forward********************//
void move_forward() {
  for (int i = 0; i <= 5; i++) {
    lh2.write(180 - (i * 2));
    rl1.write( 90 + i);
    rl5.write( 90 + i);
    ll1.write( 90 + i);
    ll5.write( 90 + i);
    delay(50);
  }
  for (int i = 0; i <= 10; i++) {
    for (int i = 0; i <= 20; i++) {
      rh1.write(0 + i);
      ll2.write(30 + i);
      ll4.write(150 + i);
      delay(50);
    }
    for (int i = 0; i <= 20; i++) {
      if (i <= 10) {
        lh2.write(160 + i * 2);
        rh2.write(0 + i * 2);
      }
      rh1.write(20 - i);
      ll2.write(50 - i);
      ll4.write(170 - i);
      if (i <= 10) {
        rl1.write( 95 - i);
        rl5.write( 95 - i);
        ll1.write( 95 - i);
        ll5.write( 95 - i);
      }
      delay(50);
    }
    for (int i = 0; i <= 20; i++) {
      lh1.write(180 - i);
      rl2.write(150 - i);
      rl4.write(30 - i);
      delay(50);
    }
    for (int i = 0; i <= 30; i++) {
      if (i <= 10) {
        lh2.write(180 - i * 2);
        rh2.write(20 - i * 2);
      }
      lh1.write(160 + i);
      rl2.write(130 + i);
      rl4.write(10 + i);
      if (i <= 10) {
        rl1.write( 85 + i);
        rl5.write( 85 + i);
        ll1.write( 85 + i);
        ll5.write( 85 + i);
      }
      delay(50);
    }
  }
  for (int i = 0; i <= 5; i++) {
    lh2.write(170 + (i * 2));
    rl1.write( 95 - i);
    rl5.write( 95 - i);
    ll1.write( 95 - i);
    ll5.write( 95 - i);
    delay(50);
  }
}

//********************turn left********************//
void turn_left() {
  for (int i = 1; i <= 30; i++) {
    for (int i = 0; i <= 5; i++) {
      rh2.write(0 + (i * 2));
      rl1.write( 90 - i);
      rl5.write( 90 - i);
      ll1.write( 90 - i);
      ll5.write( 90 - i);
      delay(30);
    }
    for (int i = 0; i <= 10; i++) {
      lh1.write(180 - i);
      if (i % 2 == 0) {
        ll2.write(30 + i / 2);
      }
      rl2.write(150 - i);
      rl4.write(30 - i);
      delay(30);
    }
    for (int i = 0; i <= 30; i++) {
      lh1.write(150 + i);
      if (i % 2 == 0) {
        ll2.write(45 - i / 2);
      }
      rl2.write(120 + i);
      rl4.write(0 + i);
      delay(30);
    }
    for (int i = 0; i <= 5; i++) {
      rh2.write(10 - i * 2);
      rl1.write( 85 + i);
      rl5.write( 85 + i);
      ll1.write( 85 + i);
      ll5.write( 85 + i);
      delay(30);
    }
  }
}
//********************turn right********************//
void turn_right() {
  for (int i = 1; i <= 30; i++) {
    for (int i = 0; i <= 5; i++) {
      lh2.write(180 - (i * 2));
      rl1.write( 90 + i);
      rl5.write( 90 + i);
      ll1.write( 90 + i);
      ll5.write( 90 + i);
      delay(30);
    }
    for (int i = 0; i <= 10; i++) {
      rh1.write(0 + i);
      if (i % 2 == 0) {
        rl2.write(150 - i / 2);
      }
      ll2.write(30 + i);
      ll4.write(150 + i);
      delay(30);
    }
    for (int i = 0; i <= 30; i++) {
      rh1.write(30 - i);
      if (i % 2 == 0) {
        rl2.write(135 + i / 2);
      }
      ll2.write(60 - i);
      ll4.write(180 - i);
      delay(30);
    }
    for (int i = 0; i <= 5; i++) {
      lh2.write(170 + i * 2);
      rl1.write( 95 - i);
      rl5.write( 95 - i);
      ll1.write( 95 - i);
      ll5.write( 95 - i);
      delay(30);
    }
  }
}
//********************push ups********************//
void push_ups() {
  for (int i = 0; i <= 60; i++) {
    if (i <= 30) {
      lh2.write(180 - i);
      rh2.write(0 + i);
      rh1.write(0 + i);
      lh1.write(180 - i);
    }
    if (i % 2 == 0) {
      rh3.write(20 + i / 2);
      lh3.write(160 - i / 2);
    }
    rl2.write(150 - i);
    ll2.write(30 + i);
    rl3.write(30 + (i * 2));
    ll3.write(150 - (i * 2));
    rl4.write(30 + i);
    ll4.write(150 - i);
    delay(100);
  }
  for (int i = 0; i <= 60; i++) {
    rl1.write( 90 - i);
    rl5.write( 90 - i);
    ll1.write( 90 + i);
    ll5.write( 90 + i);
    if (i % 2 == 0) {
      lh1.write(150 - i);
      rh1.write(30 + i);
    }
    delay(50);
  }
  for (int i = 0; i <= 30; i++) {
    rl1.write( 30 - i);
    ll1.write( 150 + i);
    delay(50);
  }
  for (int i = 0; i <= 90; i++) {
    if (i <= 60) {
      rh3.write(50 + i);
      lh3.write(130 - i);
    }
    rl2.write( 90 + i);
    ll2.write( 90 - i);
    delay(50);
  }
  for (int i = 0; i <= 90; i++) {
    if (i % 3 == 0) {
      rl2.write( 180 - i / 3);
      ll2.write( 0 + i / 3);
    }
    if (i <= 60) {
      rl5.write( 30 + i);
      ll5.write( 150 - i);
    }
    rl1.write( 0 + i);
    ll1.write( 180 - i);
    delay(50);
  }
  for (int i = 0; i <= 60; i++) {
    rl3.write(150 - (i * 2));
    ll3.write(30 + (i * 2));
    rl4.write(90 - i);
    ll4.write(90 + i);
    delay(50);
  }
  delay(10000);
  //pushup
  for (int i = 1; i <= 100; i++) {
    for (int i = 0; i <= 30; i++) {
      rh2.write(60 - i );
      lh2.write(120 + i );
      rh3.write(110 - i);
      lh3.write(70 + i);
      delay(50);
    }
    for (int i = 0; i <= 30; i++) {
      rh2.write(30 + i );
      lh2.write(150 - i );
      rh3.write(80 + i);
      lh3.write(100 - i);
      delay(50);
    }
  }
}

//********************gangnam style********************//
void gangnam_style_dance() {
  gangnam_style1();
  gangnam_style2_right();
  gangnam_style3();
  gangnam_style2_left();
  gangnam_style3();
}
void gangnam_style1() {
  for (int i = 0; i <= 30; i++) {
    rh2.write(0 + i);
    lh2.write(180 - i);
    if (i <= 25) {
      rh3.write(20 + i * 2);
      lh3.write(160 - i * 2);
    }
    delay(20);
  }
  for (int i = 1; i <= 5; i++) {
    for (int i = 0; i <= 20; i++) {
      ll2.write(30 + i);
      ll3.write(150 - (i * 2));
      ll4.write(150 - i);
      delay(30);
    }
    for (int i = 0; i <= 20; i++) {
      ll2.write(50 - i);
      ll3.write(110 + (i * 2));
      ll4.write(130 + i);
      delay(30);
    }
  }
  for (int i = 0; i <= 30; i++) {
    rh2.write(30 - i);
    lh2.write(150 + i);
    if (i <= 25) {
      rh3.write(70 - i * 2);
      lh3.write(110 + i * 2);
    }
    delay(20);
  }
}
//////////////////////////////////
void gangnam_style2_right() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(0 + i);
    if (i <= 80) {
      lh1.write(180 - i);
      lh3.write(160 - i);
    }
    delay(15);
  }
  for (int i = 1; i <= 10; i++) {
    for (int i = 0; i <= 20; i++) {
      rh1.write(180 - i);
      ll5.write( 90 + i);
      rl5.write( 90 - i);
      delay(30);
    }
    for (int i = 0; i <= 20; i++) {
      rh1.write(160 + i);
      ll5.write(  110 - i);
      rl5.write( 70 + i);
      delay(30);
    }
  }
  for (int i = 0; i <= 180; i++) {
    rh1.write(180 - i);
    if (i <= 80) {
      lh1.write(100 + i);
      lh3.write(80 + i);
    }
    delay(15);
  }
  delay(500);
}
////////////////////////////////////////////
void gangnam_style2_left() {
  for (int i = 0; i <= 180; i++) {
    lh1.write(180 - i);
    if (i <= 80) {
      rh1.write(0 + i);
      rh3.write(20 + i);
    }
    delay(15);
  }
  for (int i = 1; i <= 10; i++) {
    for (int i = 0; i <= 20; i++) {
      lh1.write(0 + i);
      ll5.write( 90 + i);
      rl5.write( 90 - i);
      delay(30);
    }
    for (int i = 0; i <= 20; i++) {
      lh1.write(20 - i);
      ll5.write(  110 - i);
      rl5.write( 70 + i);
      delay(30);
    }
  }
  for (int i = 0; i <= 180; i++) {
    lh1.write(0 + i);
    if (i <= 80) {
      rh1.write(80 - i);
      rh3.write(100 - i);
    }
    delay(15);
  }
  delay(500);
}
////////////////////////////////////
void gangnam_style3() {
  for (int i = 0; i <= 90; i++) {
    lh1.write(180 - i);
    if (i <= 70) {
      rh1.write(0 + i);
    }
    delay(15);
  }
  for (int i = 0; i <= 70; i++) {
    rh3.write(20 + i);
    lh3.write(160 - i);
    delay(15);
  }
  for (int i = 1; i <= 10; i++) {
    for (int i = 0; i <= 20; i++) {
      lh1.write(90 - i);
      rh1.write(70 + i);
      ll5.write( 90 + i);
      rl5.write( 90 - i);
      delay(20);
    }
    for (int i = 0; i <= 20; i++) {
      lh1.write(70 + i);
      rh1.write(90 - i);
      ll5.write(  110 - i);
      rl5.write( 70 + i);
      delay(20);
    }
  }
  for (int i = 0; i <= 70; i++) {
    rh3.write(90 - i);
    lh3.write(90 + i);
    delay(15);
  }
  for (int i = 0; i <= 90; i++) {
    lh1.write(90 + i);
    if (i <= 70) {
      rh1.write(70 - i);
    }
    delay(15);
  }
}
//********************dance steps********************//
void dance_steps() {
  do_bow();
  dance_move1();
  dance_move2();
  dance_move3();
  dance_move4();
  dance_move5();
  dance_move6();
  gangnam_style3();
  dance_move7();
  do_bow();
}
void dance_move1() {
  for (int i = 1; i <= 10; i++) {
    for (int i = 0; i <= 20; i++) {
      rl5.write( 90 - i);
      delay(25);
    }
    for (int i = 0; i <= 20; i++) {
      rl5.write( 70 + i);
      delay(25);
    }
  }
}
//////////////////////////////////
void dance_move2() {
  for (int i = 1; i <= 5; i++) {
    for (int i = 0; i <= 30; i++) {
      lh2.write( 180 - i);
      lh3.write( 160 - i);
      delay(15);
    }
    for (int i = 0; i <= 30; i++) {
      rh2.write( 0 + i);
      rh3.write( 20 + i);
      delay(15);
    }
    for (int i = 0; i <= 30; i++) {
      lh2.write( 150 + i);
      lh3.write( 130 + i);
      delay(15);
    }
    for (int i = 0; i <= 30; i++) {
      rh2.write( 30 - i);
      rh3.write( 50 - i);
      delay(15);
    }
  }
}
///////////////////////////////
void dance_move3() {
  for (int k = 1; k <= 3; k++) {
    for (int i = 0; i <= 30; i++) {
      rh2.write( 0 + i);
      rh3.write( 20 + i);
      if (i % 3 == 0) {
        Serial.println(i / 3);
        rl1.write( 90 - i / 3);
        rl5.write( 90 - i / 3);
        ll1.write( 90 - i / 3);
        ll5.write( 90 - i / 3);
      }
      delay(20);
    }
    for (int i = 0; i <= 30; i++) {
      rh2.write( 30 - i);
      rh3.write( 50 - i);
      if (i % 3 == 0) {
        Serial.println(i / 3);
        rl1.write( 80 + i / 3);
        rl5.write( 80 + i / 3);
        ll1.write( 80 + i / 3);
        ll5.write( 80 + i / 3);
      }
      delay(20);
    }
    for (int i = 0; i <= 30; i++) {
      lh2.write( 180 - i);
      lh3.write( 160 - i);
      if (i % 3 == 0) {
        Serial.println(i / 3);
        rl1.write( 90 + i / 3);
        rl5.write( 90 + i / 3);
        ll1.write( 90 + i / 3);
        ll5.write( 90 + i / 3);
      }
      delay(20);
    }
    for (int i = 0; i <= 30; i++) {
      lh2.write( 150 + i);
      lh3.write( 130 + i);
      if (i % 3 == 0) {
        Serial.println(i / 3);
        rl1.write( 100 - i / 3);
        rl5.write( 100 - i / 3);
        ll1.write( 100 - i / 3);
        ll5.write( 100 - i / 3);
      }
      delay(20);
    }
  }
}
//////////////////////////////
void dance_move4() {
  for (int i = 0; i <= 180; i++) {
    rh1.write( 0 + i);
    lh1.write( 180 - i);
    delay(15);
  }
  for (int i = 1; i <= 3; i++) {
    for (int i = 0; i <= 20; i++) {
      rh2.write( 0 + i * 2);
      lh2.write( 180 - i * 2);
      rh3.write( 20 + i * 2);
      lh3.write( 160 - i * 2);
      ll5.write( 90 + i);
      rl5.write( 90 - i);
      delay(30);
    }
    for (int i = 0; i <= 20; i++) {
      rh2.write( 40 - i * 2);
      lh2.write( 140 + i * 2);
      rh3.write( 60 - i * 2);
      lh3.write( 120 + i * 2);
      ll5.write(  110 - i);
      rl5.write( 70 + i);
      delay(30);
    }
  }
  for (int i = 0; i <= 180; i++) {
    rh1.write( 180 - i);
    lh1.write( 0 + i);
    delay(15);
  }
}
/////////////////////////////////////////
void dance_move5() {
  for (int i = 0; i <= 180; i++) {
    lh1.write( 180 - i);
    rh1.write( 0 + i);
    if (i <= 90) {
      lh2.write( 180 - i);
      rh2.write( 0 + i);
    }
    if (i <= 70) {
      lh3.write( 160 - i);
      rh3.write( 20 + i);
    }
    delay(15);
  }
  for (int i = 0; i <= 45; i++) {
    lh3.write( 90 - i);
    rh3.write( 90 - i);
    delay(15);
  }
  for (int i = 1; i <= 3; i++) {
    for (int i = 0; i <= 90; i++) {
      lh3.write( 45 + i);
      rh3.write( 45 + i);
      delay(15);
    }
    for (int i = 0; i <= 90; i++) {
      lh3.write( 135 - i);
      rh3.write( 135 - i);
      delay(15);
    }
  }
  for (int i = 0; i <= 45; i++) {
    lh3.write( 45 + i);
    rh3.write( 45 + i);
    delay(15);
  }
  //zigzag hand move
  for (int i = 0; i <= 180; i++) {
    lh1.write( 0 + i);
    delay(15);
  }
  for (int i = 1; i <= 3; i++) {
    for (int i = 0; i <= 180; i++) {
      lh1.write( 180 - i);
      rh1.write( 180 - i);
      delay(15);
    }
    for (int i = 0; i <= 180; i++) {
      lh1.write( 0 + i);
      rh1.write( 0 + i);
      delay(15);
    }
  }
  for (int i = 0; i <= 180; i++) {
    lh1.write( 180 - i);
    delay(15);
  }
  for (int i = 0; i <= 180; i++) {
    lh1.write( 0 + i);
    rh1.write( 180 - i);
    if (i <= 90) {
      lh2.write( 90 + i);
      rh2.write( 90 - i);
    }
    if (i <= 70) {
      lh3.write( 90 + i);
      rh3.write( 90 - i);
    }
    delay(15);
  }
}
//////////////////////////////////////////////////
void dance_move6() {
  for (int i = 0; i <= 45; i++) {
    rh2.write(0 + i); //45
    lh2.write(180 - i); //135
    if (i <= 25) {
      rh3.write(20 + i);//45
      lh3.write(160 - i);//135
    }
    delay(15);
  }
  for (int i = 0; i <= 10; i++) {
    rh3.write(45 - (i * 2));
    lh3.write(135 - (i * 2));
    rl1.write( 90 + i);
    rl5.write( 90 + i);
    ll1.write( 90 + i);
    ll5.write( 90 + i);
    head.write(90 + i * 4);
    delay(50);
  }
  for (int j = 1; j <= 3; j++) {
    for (int i = 0; i <= 20; i++) {
      head.write(130 - i * 4);
      rh3.write(25 + (i * 2));
      lh3.write(115 + (i * 2));

      rl1.write( 100 - i);
      rl5.write( 100 - i);
      ll1.write( 100 - i);
      ll5.write( 100 - i);
      delay(50);
    }
    for (int i = 0; i <= 20; i++) {
      head.write(50 + i * 4);
      rh3.write(65 - (i * 2));
      lh3.write(155 - (i * 2));

      rl1.write( 80 + i);
      rl5.write( 80 + i);
      ll1.write( 80 + i);
      ll5.write( 80 + i);
      delay(50);
    }
  }
  for (int i = 0; i <= 10; i++) {
    head.write(130 - i * 4);
    rh3.write(25 + (i * 2));
    lh3.write(115 + (i * 2));
    rl1.write( 100 - i);
    rl5.write( 100 - i);
    ll1.write( 100 - i);
    ll5.write( 100 - i);
    delay(50);
  }
  for (int i = 0; i <= 45; i++) {
    rh2.write(45 - i); //45
    lh2.write(135 + i); //135
    if (i <= 25) {
      rh3.write(45 - i);//45
      lh3.write(135 + i);//135
    }
    delay(15);
  }
}
//////////////////////////////////////
void dance_move7() {
  for (int i = 0; i <= 20; i++) {
    rh3.write(20 - i);
    lh3.write(160 + i);
    delay(15);
  }
  for (int i = 1; i <= 5; i++) {
    for (int i = 0; i <= 60; i++) {
      rh1.write(0 + i);//60
      lh2.write(180 - i);// 120
      rh3.write(0 + i);//80
      lh3.write(180 - i);//100
      delay(10);
    }
    for (int i = 0; i <= 60; i++) {
      rh1.write(60 - i);
      lh2.write(120 + i);
      rh3.write(60 - i);
      lh3.write(120 + i);
      delay(10);
    }
    for (int i = 0; i <= 60; i++) {
      lh1.write(180 - i);
      rh2.write(0 + i);
      rh3.write(0 + i);
      lh3.write(180 - i);
      delay(10);
    }
    for (int i = 0; i <= 60; i++) {
      lh1.write(120 + i);
      rh2.write(60 - i);
      rh3.write(60 - i);
      lh3.write(120 + i);
      delay(10);
    }
  }
  for (int i = 0; i <= 20; i++) {
    rh3.write(0 + i);
    lh3.write(180 - i);
    delay(15);
  }
}