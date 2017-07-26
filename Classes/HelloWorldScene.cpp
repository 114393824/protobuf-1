#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "addressbook.pb.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    tutorial::Person person;
    person.set_name("褚少文");
    person.set_id(11);
    person.set_email("lovezhuyuan@gmail.com");
    tutorial::Person_PhoneNumber phoneNumber;
    phoneNumber.set_number("15726673236");
    phoneNumber.set_type(tutorial::Person::PhoneType::Person_PhoneType_MOBILE);
    std::string str = person.SerializeAsString();
    tutorial::Person myPerson;
    myPerson.ParseFromString(str);
    MessageBox(myPerson.email().c_str(),myPerson.name().c_str());
    //MessageBox("E-mail: %s" ,);
    google::protobuf::ShutdownProtobufLibrary();
   
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
