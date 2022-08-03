#include "map_1.h"
#include <QPalette>
#include <globalvar.h>


Map_1::Map_1(b2World * world, QGraphicsScene * scene)
{


        //Set the finish line distance along the X axis:
        defaultSetting.editFinishLinePos( 14511 );

        //Set the winning Message for the easy level:

        //Graphical set up for the map_1:
        QPixmap mapBG(":/assets/resource/map_1BG.jpg");
        mapBG.scaled(245,91,Qt::IgnoreAspectRatio);
        QPixmap sceneBG(":/assets/resource/scene_1BG.png");
        sceneBG.scaled(287,136,Qt::KeepAspectRatioByExpanding);

        QPolygonF map_background;
        map_background << QPointF ( -23.66 * SCALE , -58.53 * SCALE)
                       << QPointF (300.80 * SCALE , -58.53 * SCALE)
                       << QPointF (300.80 * SCALE , 77.92 * SCALE)
                       << QPointF (-23.66 * SCALE , 77.92 * SCALE);

        QGraphicsPolygonItem  *map_background_shape;
        map_background_shape = new QGraphicsPolygonItem(map_background);
        map_background_shape->setPos(-23.66 * SCALE, -58.53 * SCALE);
        map_background_shape->setBrush(sceneBG);

        scene->setBackgroundBrush(sceneBG);



        //setup ploygon shape of QGraphicsItem
        QPolygonF polygon_1;
        polygon_1 << QPointF( -30.0 * SCALE, 0.0 * SCALE)
                  << QPointF( 11.9413 * SCALE,0.0  * SCALE)
                  << QPointF( 35.6113 * SCALE, -10.8650  * SCALE)
                  << QPointF( 43.4384 * SCALE, -10.8650 * SCALE)
                  << QPointF( 48.1109 * SCALE, -4.9352 * SCALE)
                  << QPointF( 59.7672 * SCALE, -3.7224 * SCALE)
                  << QPointF( 71.4172 * SCALE, -12.0576 * SCALE)
                  << QPointF( 83.6005 * SCALE, -14.2559 * SCALE)
                  << QPointF( 93.6973 * SCALE, -12.2053 * SCALE)
                  << QPointF( 112.2810 * SCALE, -4.1443 * SCALE)
                  << QPointF( 119.9571 * SCALE, -0.8964 * SCALE)
                  << QPointF( 129.9759 * SCALE, -0.2381 * SCALE)
                  << QPointF( 148.4152 * SCALE, -7.3853 * SCALE)
                  << QPointF( 180.7053 * SCALE, -16.3993 * SCALE)
                  << QPointF( 194.4772 * SCALE, -24.6452 * SCALE)
                  << QPointF( 203.4119 * SCALE, -24.6452 * SCALE)
                  << QPointF( 213.7692 * SCALE, -28.3414 * SCALE)
                  << QPointF( 229.5331 * SCALE, -35.5798 * SCALE)
                  << QPointF( 249.7615 * SCALE, -35.5798 * SCALE)
                  << QPointF( 249.7615* SCALE, 55.1978 * SCALE)
                  << QPointF( 0.0 * SCALE, 55.1978 * SCALE);




        polygonShape_1 = new QGraphicsPolygonItem(polygon_1);
        polygonShape_1->setPos(0.0 * SCALE, 3.5 * SCALE);


        polygonShape_1->setBrush(mapBG);


        scene->addItem(map_background_shape);
        scene->addItem(polygonShape_1);


        b2Vec2 vertice_1[4];
        vertice_1[0].Set(-30.0f, 0.0f);
        vertice_1[1].Set(11.9413f, 0.0f);
        vertice_1[2].Set(11.9413f, 55.0f);
        vertice_1[3].Set(-30.0f, 55.0f);

        b2Vec2 vertice_2[4];
        vertice_2[0].Set(11.9413f, 0.0f);
        vertice_2[1].Set(35.6113f, -10.8650f);
        vertice_2[2].Set(35.6113f, 55.0f);
        vertice_2[3].Set(11.9413f, 55.0f);

        b2Vec2 vertice_3[4];
        vertice_3[0].Set(35.6113f, -10.8650f);
        vertice_3[1].Set(43.4384f, -10.8650f);
        vertice_3[2].Set(43.4384f, 50.0f);
        vertice_3[3].Set(35.6113f, 50.0f);

        b2Vec2 vertice_4[4];
        vertice_4[0].Set(43.4384f, -10.8650f);
        vertice_4[1].Set(48.1109f, -4.9352f);
        vertice_4[2].Set(48.1109f, 50.0f);
        vertice_4[3].Set(43.4384f, 50.0f);

        b2Vec2 vertice_5[4];
        vertice_5[0].Set(48.1109f, -4.9352f);
        vertice_5[1].Set(59.7672f, -3.7224f);
        vertice_5[2].Set(59.7672f, 50.0f);
        vertice_5[3].Set(48.1109f, 50.0f);

        b2Vec2 vertice_6[4];
        vertice_6[0].Set(59.7672f, -3.7224f);
        vertice_6[1].Set(71.4172f,-12.0576f);
        vertice_6[2].Set(71.4172f, 50.0f);
        vertice_6[3].Set(59.7672f, 50.0f);

        b2Vec2 vertice_7[4];
        vertice_7[0].Set(71.4172f,-12.0576f);
        vertice_7[1].Set(83.6005f, -14.2559f);
        vertice_7[2].Set(83.6005f, 50.0f);
        vertice_7[3].Set(71.4172f, 50.0f);

        b2Vec2 vertice_8[4];
        vertice_8[0].Set(83.6005f, -14.2559f);
        vertice_8[1].Set(93.6973f, -12.2053f);
        vertice_8[2].Set(93.6973f, 50.0f);
        vertice_8[3].Set(83.6005f, 50.0f);

        b2Vec2 vertice_9[4];
        vertice_9[0].Set(93.6973f, -12.2053f);
        vertice_9[1].Set(112.2810f, -4.1443f);
        vertice_9[2].Set(112.2810f, 50.0f);
        vertice_9[3].Set(93.6973f, 50.0f);

        b2Vec2 vertice_10[4];
        vertice_10[0].Set(112.2810f, -4.1443f);
        vertice_10[1].Set(119.9571f, -0.8964f);
        vertice_10[2].Set(119.9571f, 50.0f);
        vertice_10[3].Set(112.2810f, 50.0f);

        b2Vec2 vertice_11[4];
        vertice_11[0].Set(119.9571f, -0.8964f);
        vertice_11[1].Set(129.9759f, -0.2381f);
        vertice_11[2].Set(129.9759f, 50.0f);
        vertice_11[3].Set(119.9571f, 50.0f);

        b2Vec2 vertice_12[4];
        vertice_12[0].Set(129.9759f, -0.2381f);
        vertice_12[1].Set(148.4152f, -7.3853f);
        vertice_12[2].Set(148.4152f, 50.0f);
        vertice_12[3].Set(129.9759f, 50.0f);

        b2Vec2 vertice_13[4];
        vertice_13[0].Set(148.4152f, -7.3853f);
        vertice_13[1].Set(180.7053f, -16.3993f);
        vertice_13[2].Set(180.7053f, 50.0f);
        vertice_13[3].Set(148.4152f, 50.0f);

        b2Vec2 vertice_14[4];
        vertice_14[0].Set(180.7053f, -16.3993f);
        vertice_14[1].Set(194.4772f, -24.6452f);
        vertice_14[2].Set(194.4772f, 50.0f);
        vertice_14[3].Set(180.7053f, 50.0f);

        b2Vec2 vertice_15[4];
        vertice_15[0].Set(194.4772f, -24.6452f);
        vertice_15[1].Set(203.4119f, -24.6452f);
        vertice_15[2].Set(203.4119f, 50.0f);
        vertice_15[3].Set(194.4772f, 50.0f);

        b2Vec2 vertice_16[4];
        vertice_16[0].Set(203.4119f, -24.6452f);
        vertice_16[1].Set(213.7692f, -28.3414f);
        vertice_16[2].Set(213.7692f, 50.0f);
        vertice_16[3].Set(203.4119f, 50.0f);

        b2Vec2 vertice_17[4];
        vertice_17[0].Set(213.7692f, -28.3414f);
        vertice_17[1].Set(229.5331f,  -35.5798f);
        vertice_17[2].Set(229.5331f, 50.0f);
        vertice_17[3].Set(213.7692f, 50.0f);

        b2Vec2 vertice_18[4];
        vertice_18[0].Set(229.5331f,  -35.5798f);
        vertice_18[1].Set(249.7615f, -35.5798f);
        vertice_18[2].Set(249.7615f, 50.0f);
        vertice_18[3].Set(229.5331f, 50.0f);
        b2Vec2 antiReverseFalling[4];
        antiReverseFalling[0].Set(0.0f,0.0f);
        antiReverseFalling[1].Set(0.0f,-30.0f);
        antiReverseFalling[2].Set(-1.0f,-30.0f);
        antiReverseFalling[3].Set(-1.0f,-30.0f);

        b2PolygonShape  shape_1, shape_2, shape_3, shape_4,
                        shape_5, shape_6, shape_7, shape_8,
                        shape_9, shape_10, shape_11, shape_12,
                        shape_13, shape_14, shape_15, shape_16,
                        shape_17, shape_18, antiReverseShape;

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
        antiReverseShape.Set(antiReverseFalling,4);

        b2BodyDef bodyDef;
        bodyDef.type = b2_staticBody;
        bodyDef.position.Set(0.0f, 3.5f);

        body = world->CreateBody(&bodyDef);


        b2FixtureDef fixtureDef_1;
        fixtureDef_1.shape = &shape_1;
        fixtureDef_1.density = 5.0f;
        fixtureDef_1.friction = 1.0f;
        body->CreateFixture(&fixtureDef_1);


        b2FixtureDef fixtureDef_2;
        fixtureDef_2.shape = &shape_2;
        fixtureDef_2.density = 5.0f;
        fixtureDef_2.friction = 1.0f;
        body->CreateFixture(&fixtureDef_2);


        b2FixtureDef fixtureDef_3;
        fixtureDef_3.shape = &shape_3;
        fixtureDef_3.density = 5.0f;
        fixtureDef_3.friction = 1.0f;
        body->CreateFixture(&fixtureDef_3);


        b2FixtureDef fixtureDef_4;
        fixtureDef_4.shape = &shape_4;
        fixtureDef_4.density = 5.0f;
        fixtureDef_4.friction = 1.0f;
        body->CreateFixture(&fixtureDef_4);


        b2FixtureDef fixtureDef_5;
        fixtureDef_5.shape = &shape_5;
        fixtureDef_5.density = 5.0f;
        fixtureDef_5.friction = 1.0f;
        body->CreateFixture(&fixtureDef_5);


        b2FixtureDef fixtureDef_6;
        fixtureDef_6.shape = &shape_6;
        fixtureDef_6.density = 5.0f;
        fixtureDef_6.friction = 1.0f;
        body->CreateFixture(&fixtureDef_6);


        b2FixtureDef fixtureDef_7;
        fixtureDef_7.shape = &shape_7;
        fixtureDef_7.density = 5.0f;
        fixtureDef_7.friction = 1.0f;
        body->CreateFixture(&fixtureDef_7);


        b2FixtureDef fixtureDef_8;
        fixtureDef_8.shape = &shape_8;
        fixtureDef_8.density = 5.0f;
        fixtureDef_8.friction = 1.0f;
        body->CreateFixture(&fixtureDef_8);


        b2FixtureDef fixtureDef_9;
        fixtureDef_9.shape = &shape_9;
        fixtureDef_9.density = 5.0f;
        fixtureDef_9.friction = 1.0f;
        body->CreateFixture(&fixtureDef_9);


        b2FixtureDef fixtureDef_10;
        fixtureDef_10.shape = &shape_10;
        fixtureDef_10.density = 5.0f;
        fixtureDef_10.friction = 1.0f;
        body->CreateFixture(&fixtureDef_10);


        b2FixtureDef fixtureDef_11;
        fixtureDef_11.shape = &shape_11;
        fixtureDef_11.density = 5.0f;
        fixtureDef_11.friction = 1.0f;
        body->CreateFixture(&fixtureDef_11);


        b2FixtureDef fixtureDef_12;
        fixtureDef_12.shape = &shape_12;
        fixtureDef_12.density = 5.0f;
        fixtureDef_12.friction = 1.0f;
        body->CreateFixture(&fixtureDef_12);


        b2FixtureDef fixtureDef_13;
        fixtureDef_13.shape = &shape_13;
        fixtureDef_13.density = 5.0f;
        fixtureDef_13.friction = 1.0f;
        body->CreateFixture(&fixtureDef_13);


        b2FixtureDef fixtureDef_14;
        fixtureDef_14.shape = &shape_14;
        fixtureDef_14.density = 5.0f;
        fixtureDef_14.friction = 1.0f;
        body->CreateFixture(&fixtureDef_14);


        b2FixtureDef fixtureDef_15;
        fixtureDef_15.shape = &shape_15;
        fixtureDef_15.density = 5.0f;
        fixtureDef_15.friction = 1.0f;
        body->CreateFixture(&fixtureDef_15);


        b2FixtureDef fixtureDef_16;
        fixtureDef_16.shape = &shape_16;
        fixtureDef_16.density = 5.0f;
        fixtureDef_16.friction = 1.0f;
        body->CreateFixture(&fixtureDef_16);


        b2FixtureDef fixtureDef_17;
        fixtureDef_17.shape = &shape_17;
        fixtureDef_17.density = 5.0f;
        fixtureDef_17.friction = 1.0f;
        body->CreateFixture(&fixtureDef_17);


        b2FixtureDef fixtureDef_18;
        fixtureDef_18.shape = &shape_18;
        fixtureDef_18.density = 5.0f;
        fixtureDef_18.friction = 1.0f;
        body->CreateFixture(&fixtureDef_18);

        b2FixtureDef antiReverseFixture;
        antiReverseFixture.shape = &antiReverseShape;
        antiReverseFixture.density = 5.0f;
        antiReverseFixture.friction = 0.0f;
        body->CreateFixture(&antiReverseFixture);

}


