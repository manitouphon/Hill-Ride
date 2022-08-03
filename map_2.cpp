#include "map_2.h"
#include "globalvar.h"
#include <QPalette>
#include <QPointF>

Map_2::Map_2(b2World * world, QGraphicsScene * scene)
{
    defaultSetting.editFinishLinePos(30631);
    //setup ploygon shape of QGraphicsItem

    //Graphical set up for the map_1:
    QPixmap map2BG(":/assets/resource/map_2BG.jpg");
    map2BG.scaled(245,91,Qt::IgnoreAspectRatio);
    QPixmap scene2BG(":/assets/resource/scene_2BG.jpg");
    scene2BG.scaled(760,500,Qt::KeepAspectRatioByExpanding);



    QPolygonF map_background;
    map_background << QPointF ( -500 * SCALE , -500 * SCALE)
                   << QPointF (760 * SCALE , -500 * SCALE)
                   << QPointF (760 * SCALE , 500* SCALE)
                   << QPointF (-760 * SCALE , 500 * SCALE);

    QGraphicsPolygonItem  *map_background_shape;
    map_background_shape = new QGraphicsPolygonItem(map_background);
    map_background_shape->setPos(-23.66 * SCALE, 58.53 * SCALE);
    map_background_shape->setBrush(scene2BG);



        //Points Set up:
    QPolygonF polygon_1;
    polygon_1 << QPointF( -30.0* SCALE, 0 * SCALE)
            << QPointF( 11.94* SCALE, 0 * SCALE)
            << QPointF( 15.29* SCALE, 1.61 * SCALE)
            << QPointF( 19.77* SCALE, 5.32 * SCALE)
            << QPointF( 25.76* SCALE, 7.07 * SCALE)
            << QPointF( 36.03* SCALE, 6.3 * SCALE)
            << QPointF( 42.17* SCALE, 2.48 * SCALE)
            << QPointF( 50.64* SCALE, 1.4 * SCALE)
            << QPointF( 60.8* SCALE, -4.31 * SCALE)
            << QPointF( 81.15* SCALE, -4.31 * SCALE)
            << QPointF( 89.36* SCALE, -7.99 * SCALE)
            << QPointF( 99.58* SCALE, -16.5 * SCALE)
            << QPointF( 108.15* SCALE, -20.94 * SCALE)
            << QPointF( 123.89* SCALE, -20.93 * SCALE)
            << QPointF( 139.38* SCALE, -13.31 * SCALE)
            << QPointF( 149.13* SCALE, 0.09 * SCALE)
            << QPointF( 158.89* SCALE, 6.87 * SCALE)
            << QPointF( 166.84* SCALE, 8.11 * SCALE)
            << QPointF( 181.54* SCALE, 6.15 * SCALE)
            << QPointF( 198.22* SCALE, -0.45 * SCALE)
            << QPointF( 219.74* SCALE, -7.87 * SCALE)
            << QPointF( 239.01* SCALE, -21.76 * SCALE)
            << QPointF( 254.89* SCALE, -30.94 * SCALE)
            << QPointF( 284.09* SCALE, -36.54 * SCALE)
            << QPointF( 316.48* SCALE, -34.4 * SCALE)
            << QPointF( 345.06* SCALE, -14.96 * SCALE)
            << QPointF( 371.19* SCALE, -7.36 * SCALE)
            << QPointF( 407.71* SCALE, 7.14 * SCALE)
            << QPointF( 457.71* SCALE, 4.48 * SCALE)
            << QPointF( 486.67* SCALE, -16.16 * SCALE)
            << QPointF( 543.86* SCALE, -16.16 * SCALE)
            << QPointF( 543.86* SCALE, 55.0 * SCALE)
            << QPointF( 0.0 * SCALE, 55.0 * SCALE);



    polygonShape_1 = new QGraphicsPolygonItem(polygon_1);
    polygonShape_1->setPos(0.0 * SCALE, 3.5 * SCALE);

    polygonShape_1->setPen(QPen(Qt::cyan, 2));
    polygonShape_1->setBrush(map2BG);

    scene->addItem(map_background_shape);
    scene->addItem(polygonShape_1);

    
    b2Vec2 vertice_0[4];
    vertice_0[0].Set(0.0f, 0.0f);
    vertice_0[1].Set(11.94f, 0.0f);
    vertice_0[2].Set(11.94f, 50.0f);
    vertice_0[3].Set(0.0f, 50.0f);
    
    b2Vec2 vertice_1[4];
    vertice_1[0].Set(11.94f, 0.0f);
    vertice_1[1].Set(15.29f, 1.61f);
    vertice_1[2].Set(15.29f, 50.0f);
    vertice_1[3].Set(11.94f, 50.0f);
    
    b2Vec2 vertice_2[4];
    vertice_2[0].Set(15.29f, 1.61f);
    vertice_2[1].Set(19.77f, 5.32f);
    vertice_2[2].Set(19.77f, 50.0f);
    vertice_2[3].Set(15.29f, 50.0f);
    
    b2Vec2 vertice_3[4];
    vertice_3[0].Set(19.77f, 5.32f);
    vertice_3[1].Set(25.76f, 7.07f);
    vertice_3[2].Set(25.76f, 50.0f);
    vertice_3[3].Set(19.77f, 50.0f);
    
    b2Vec2 vertice_4[4];
    vertice_4[0].Set(25.76f, 7.07f);
    vertice_4[1].Set(36.03f, 6.3f);
    vertice_4[2].Set(36.03f, 50.0f);
    vertice_4[3].Set(25.76f, 50.0f);
    
    b2Vec2 vertice_5[4];
    vertice_5[0].Set(36.03f, 6.3f);
    vertice_5[1].Set(42.17f, 2.48f);
    vertice_5[2].Set(42.17f, 50.0f);
    vertice_5[3].Set(36.03f, 50.0f);
    
    b2Vec2 vertice_6[4];
    vertice_6[0].Set(42.17f, 2.48f);
    vertice_6[1].Set(50.64f, 1.4f);
    vertice_6[2].Set(50.64f, 50.0f);
    vertice_6[3].Set(42.17f, 50.0f);
    
    b2Vec2 vertice_7[4];
    vertice_7[0].Set(50.64f, 1.4f);
    vertice_7[1].Set(60.8f, -4.31f);
    vertice_7[2].Set(60.8f, 50.0f);
    vertice_7[3].Set(50.64f, 50.0f);
    
    b2Vec2 vertice_8[4];
    vertice_8[0].Set(60.8f, -4.31f);
    vertice_8[1].Set(81.15f, -4.31f);
    vertice_8[2].Set(81.15f, 50.0f);
    vertice_8[3].Set(60.8f, 50.0f);
    
    b2Vec2 vertice_9[4];
    vertice_9[0].Set(81.15f, -4.31f);
    vertice_9[1].Set(89.36f, -7.99f);
    vertice_9[2].Set(89.36f, 50.0f);
    vertice_9[3].Set(81.15f, 50.0f);
    
    b2Vec2 vertice_10[4];
    vertice_10[0].Set(89.36f, -7.99f);
    vertice_10[1].Set(99.58f, -16.5f);
    vertice_10[2].Set(99.58f, 50.0f);
    vertice_10[3].Set(89.36f, 50.0f);
    
    b2Vec2 vertice_11[4];
    vertice_11[0].Set(99.58f, -16.5f);
    vertice_11[1].Set(108.15f, -20.94f);
    vertice_11[2].Set(108.15f, 50.0f);
    vertice_11[3].Set(99.58f, 50.0f);
    
    b2Vec2 vertice_12[4];
    vertice_12[0].Set(108.15f, -20.94f);
    vertice_12[1].Set(123.89f, -20.93f);
    vertice_12[2].Set(123.89f, 50.0f);
    vertice_12[3].Set(108.15f, 50.0f);
    
    b2Vec2 vertice_13[4];
    vertice_13[0].Set(123.89f, -20.93f);
    vertice_13[1].Set(139.38f, -13.31f);
    vertice_13[2].Set(139.38f, 50.0f);
    vertice_13[3].Set(123.89f, 50.0f);
    
    b2Vec2 vertice_14[4];
    vertice_14[0].Set(139.38f, -13.31f);
    vertice_14[1].Set(149.13f, 0.09f);
    vertice_14[2].Set(149.13f, 50.0f);
    vertice_14[3].Set(139.38f, 50.0f);
    
    b2Vec2 vertice_15[4];
    vertice_15[0].Set(149.13f, 0.09f);
    vertice_15[1].Set(158.89f, 6.87f);
    vertice_15[2].Set(158.89f, 50.0f);
    vertice_15[3].Set(149.13f, 50.0f);
    
    b2Vec2 vertice_16[4];
    vertice_16[0].Set(158.89f, 6.87f);
    vertice_16[1].Set(166.84f, 8.11f);
    vertice_16[2].Set(166.84f, 50.0f);
    vertice_16[3].Set(158.89f, 50.0f);
    
    b2Vec2 vertice_17[4];
    vertice_17[0].Set(166.84f, 8.11f);
    vertice_17[1].Set(181.54f, 6.15f);
    vertice_17[2].Set(181.54f, 50.0f);
    vertice_17[3].Set(166.84f, 50.0f);
    
    b2Vec2 vertice_18[4];
    vertice_18[0].Set(181.54f, 6.15f);
    vertice_18[1].Set(198.22f, -0.45f);
    vertice_18[2].Set(198.22f, 50.0f);
    vertice_18[3].Set(181.54f, 50.0f);
    
    b2Vec2 vertice_19[4];
    vertice_19[0].Set(198.22f, -0.45f);
    vertice_19[1].Set(219.74f, -7.87f);
    vertice_19[2].Set(219.74f, 50.0f);
    vertice_19[3].Set(198.22f, 50.0f);
    
    b2Vec2 vertice_20[4];
    vertice_20[0].Set(219.74f, -7.87f);
    vertice_20[1].Set(239.01f, -21.76f);
    vertice_20[2].Set(239.01f, 50.0f);
    vertice_20[3].Set(219.74f, 50.0f);
    
    b2Vec2 vertice_21[4];
    vertice_21[0].Set(239.01f, -21.76f);
    vertice_21[1].Set(254.89f, -30.94f);
    vertice_21[2].Set(254.89f, 50.0f);
    vertice_21[3].Set(239.01f, 50.0f);
    
    b2Vec2 vertice_22[4];
    vertice_22[0].Set(254.89f, -30.94f);
    vertice_22[1].Set(284.09f, -36.54f);
    vertice_22[2].Set(284.09f, 50.0f);
    vertice_22[3].Set(254.89f, 50.0f);
    
    b2Vec2 vertice_23[4];
    vertice_23[0].Set(284.09f, -36.54f);
    vertice_23[1].Set(316.48f, -34.4f);
    vertice_23[2].Set(316.48f, 50.0f);
    vertice_23[3].Set(284.09f, 50.0f);
    
    b2Vec2 vertice_24[4];
    vertice_24[0].Set(316.48f, -34.4f);
    vertice_24[1].Set(345.06f, -14.96f);
    vertice_24[2].Set(345.06f, 50.0f);
    vertice_24[3].Set(316.48f, 50.0f);
    
    b2Vec2 vertice_25[4];
    vertice_25[0].Set(345.06f, -14.96f);
    vertice_25[1].Set(371.19f, -7.36f);
    vertice_25[2].Set(371.19f, 50.0f);
    vertice_25[3].Set(345.06f, 50.0f);
    
    b2Vec2 vertice_26[4];
    vertice_26[0].Set(371.19f, -7.36f);
    vertice_26[1].Set(407.71f, 7.14f);
    vertice_26[2].Set(407.71f, 50.0f);
    vertice_26[3].Set(371.19f, 50.0f);
    
    b2Vec2 vertice_27[4];
    vertice_27[0].Set(407.71f, 7.14f);
    vertice_27[1].Set(457.71f, 4.48f);
    vertice_27[2].Set(457.71f, 50.0f);
    vertice_27[3].Set(407.71f, 50.0f);
    
    b2Vec2 vertice_28[4];
    vertice_28[0].Set(457.71f, 4.48f);
    vertice_28[1].Set(486.67f, -16.16f);
    vertice_28[2].Set(486.67f, 50.0f);
    vertice_28[3].Set(457.71f, 50.0f);
    
    b2Vec2 vertice_29[4];
    vertice_29[0].Set(486.67f, -16.16f);
    vertice_29[1].Set(543.86f, -16.16f);
    vertice_29[2].Set(543.86f, 50.0f);
    vertice_29[3].Set(486.67f, 50.0f);
    
    b2PolygonShape  shape_0, shape_1, shape_2, shape_3, shape_4,
                    shape_5, shape_6, shape_7, shape_8, shape_9, 
                    shape_10, shape_11, shape_12, shape_13, shape_14,
                    shape_15, shape_16, shape_17, shape_18, shape_19, shape_20,
                    shape_21, shape_22, shape_23, shape_24, shape_25, shape_26, shape_27, shape_28, shape_29;
                    

    shape_0.Set(vertice_0, 4);
    shape_1.Set(vertice_1, 4);
    shape_2.Set(vertice_2, 4);
    shape_3.Set(vertice_3, 4);
    shape_4.Set(vertice_4, 4);
    shape_5.Set(vertice_5, 4);
    shape_6.Set(vertice_6, 4);
    shape_7.Set(vertice_7, 4);
    shape_8.Set(vertice_8, 4);
    shape_9.Set(vertice_9, 4);
    shape_10.Set(vertice_10, 4);
    shape_11.Set(vertice_11, 4);
    shape_12.Set(vertice_12, 4);
    shape_13.Set(vertice_13, 4);
    shape_14.Set(vertice_14, 4);
    shape_15.Set(vertice_15, 4);
    shape_16.Set(vertice_16, 4);
    shape_17.Set(vertice_17, 4);
    shape_18.Set(vertice_18, 4);
    shape_19.Set(vertice_19, 4);
    shape_20.Set(vertice_20, 4);
    shape_21.Set(vertice_21, 4);
    shape_22.Set(vertice_22, 4);
    shape_23.Set(vertice_23, 4);
    shape_24.Set(vertice_24, 4);
    shape_25.Set(vertice_25, 4);
    shape_26.Set(vertice_26, 4);
    shape_27.Set(vertice_27, 4);
    shape_28.Set(vertice_28, 4);
    shape_29.Set(vertice_29, 4);


    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(0.0f,3.5f);


    body = world->CreateBody(&bodyDef);


    
    b2FixtureDef fixtureDef_0;
    fixtureDef_0.shape = &shape_0;
    fixtureDef_0.density = 5.0f;
    fixtureDef_0.friction = 0.7f;
    body->CreateFixture(&fixtureDef_0);
    
    b2FixtureDef fixtureDef_1;
    fixtureDef_1.shape = &shape_1;
    fixtureDef_1.density = 5.0f;
    fixtureDef_1.friction = 0.7f;
    body->CreateFixture(&fixtureDef_1);
    
    b2FixtureDef fixtureDef_2;
    fixtureDef_2.shape = &shape_2;
    fixtureDef_2.density = 5.0f;
    fixtureDef_2.friction = 0.7f;
    body->CreateFixture(&fixtureDef_2);
    
    b2FixtureDef fixtureDef_3;
    fixtureDef_3.shape = &shape_3;
    fixtureDef_3.density = 5.0f;
    fixtureDef_3.friction = 0.7f;
    body->CreateFixture(&fixtureDef_3);
    
    b2FixtureDef fixtureDef_4;
    fixtureDef_4.shape = &shape_4;
    fixtureDef_4.density = 5.0f;
    fixtureDef_4.friction = 0.7f;
    body->CreateFixture(&fixtureDef_4);
    
    b2FixtureDef fixtureDef_5;
    fixtureDef_5.shape = &shape_5;
    fixtureDef_5.density = 5.0f;
    fixtureDef_5.friction = 0.7f;
    body->CreateFixture(&fixtureDef_5);
    
    b2FixtureDef fixtureDef_6;
    fixtureDef_6.shape = &shape_6;
    fixtureDef_6.density = 5.0f;
    fixtureDef_6.friction = 0.7f;
    body->CreateFixture(&fixtureDef_6);
    
    b2FixtureDef fixtureDef_7;
    fixtureDef_7.shape = &shape_7;
    fixtureDef_7.density = 5.0f;
    fixtureDef_7.friction = 0.7f;
    body->CreateFixture(&fixtureDef_7);
    
    b2FixtureDef fixtureDef_8;
    fixtureDef_8.shape = &shape_8;
    fixtureDef_8.density = 5.0f;
    fixtureDef_8.friction = 0.7f;
    body->CreateFixture(&fixtureDef_8);
    
    b2FixtureDef fixtureDef_9;
    fixtureDef_9.shape = &shape_9;
    fixtureDef_9.density = 5.0f;
    fixtureDef_9.friction = 0.7f;
    body->CreateFixture(&fixtureDef_9);
    
    b2FixtureDef fixtureDef_10;
    fixtureDef_10.shape = &shape_10;
    fixtureDef_10.density = 5.0f;
    fixtureDef_10.friction = 0.7f;
    body->CreateFixture(&fixtureDef_10);
    
    b2FixtureDef fixtureDef_11;
    fixtureDef_11.shape = &shape_11;
    fixtureDef_11.density = 5.0f;
    fixtureDef_11.friction = 0.7f;
    body->CreateFixture(&fixtureDef_11);
    
    b2FixtureDef fixtureDef_12;
    fixtureDef_12.shape = &shape_12;
    fixtureDef_12.density = 5.0f;
    fixtureDef_12.friction = 0.7f;
    body->CreateFixture(&fixtureDef_12);
    
    b2FixtureDef fixtureDef_13;
    fixtureDef_13.shape = &shape_13;
    fixtureDef_13.density = 5.0f;
    fixtureDef_13.friction = 0.7f;
    body->CreateFixture(&fixtureDef_13);
    
    b2FixtureDef fixtureDef_14;
    fixtureDef_14.shape = &shape_14;
    fixtureDef_14.density = 5.0f;
    fixtureDef_14.friction = 0.7f;
    body->CreateFixture(&fixtureDef_14);
    
    b2FixtureDef fixtureDef_15;
    fixtureDef_15.shape = &shape_15;
    fixtureDef_15.density = 5.0f;
    fixtureDef_15.friction = 0.7f;
    body->CreateFixture(&fixtureDef_15);
    
    b2FixtureDef fixtureDef_16;
    fixtureDef_16.shape = &shape_16;
    fixtureDef_16.density = 5.0f;
    fixtureDef_16.friction = 0.7f;
    body->CreateFixture(&fixtureDef_16);
    
    b2FixtureDef fixtureDef_17;
    fixtureDef_17.shape = &shape_17;
    fixtureDef_17.density = 5.0f;
    fixtureDef_17.friction = 0.7f;
    body->CreateFixture(&fixtureDef_17);
    
    b2FixtureDef fixtureDef_18;
    fixtureDef_18.shape = &shape_18;
    fixtureDef_18.density = 5.0f;
    fixtureDef_18.friction = 0.7f;
    body->CreateFixture(&fixtureDef_18);
    
    b2FixtureDef fixtureDef_19;
    fixtureDef_19.shape = &shape_19;
    fixtureDef_19.density = 5.0f;
    fixtureDef_19.friction = 0.7f;
    body->CreateFixture(&fixtureDef_19);
    
    b2FixtureDef fixtureDef_20;
    fixtureDef_20.shape = &shape_20;
    fixtureDef_20.density = 5.0f;
    fixtureDef_20.friction = 0.7f;
        body->CreateFixture(&fixtureDef_20);
    
    b2FixtureDef fixtureDef_21;
    fixtureDef_21.shape = &shape_21;
    fixtureDef_21.density = 5.0f;
    fixtureDef_21.friction = 0.7f;
    body->CreateFixture(&fixtureDef_21);
    
    b2FixtureDef fixtureDef_22;
    fixtureDef_22.shape = &shape_22;
    fixtureDef_22.density = 5.0f;
    fixtureDef_22.friction = 0.7f;
    body->CreateFixture(&fixtureDef_22);
    
    b2FixtureDef fixtureDef_23;
    fixtureDef_23.shape = &shape_23;
    fixtureDef_23.density = 5.0f;
    fixtureDef_23.friction = 0.7f;
    body->CreateFixture(&fixtureDef_23); 
    
    b2FixtureDef fixtureDef_24;
    fixtureDef_24.shape = &shape_24;
    fixtureDef_24.density = 5.0f;
    fixtureDef_24.friction = 0.7f;
    body->CreateFixture(&fixtureDef_24); 
    
    b2FixtureDef fixtureDef_25;            
    fixtureDef_25.shape = &shape_25;
    fixtureDef_25.density = 5.0f;
    fixtureDef_25.friction = 0.7f;
    body->CreateFixture(&fixtureDef_25);
    
    b2FixtureDef fixtureDef_26;
    fixtureDef_26.shape = &shape_26;
    fixtureDef_26.density = 5.0f;
    fixtureDef_26.friction = 0.7f;
    body->CreateFixture(&fixtureDef_26); 
    
    b2FixtureDef fixtureDef_27;
    fixtureDef_27.shape = &shape_27;   
    fixtureDef_27.density = 5.0f;
    fixtureDef_27.friction = 0.7f;
    body->CreateFixture(&fixtureDef_27);
    
    b2FixtureDef fixtureDef_28; 
    fixtureDef_28.shape = &shape_28;  
    fixtureDef_28.density = 5.0f;
    fixtureDef_28.friction = 0.7f;
    body->CreateFixture(&fixtureDef_28);  
    
    b2FixtureDef fixtureDef_29;
    fixtureDef_29.shape = &shape_29;
    fixtureDef_29.density = 5.0f;
    fixtureDef_29.friction = 0.7f;
    body->CreateFixture(&fixtureDef_29); 
    
    



}




