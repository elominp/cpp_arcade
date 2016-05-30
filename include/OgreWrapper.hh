/*
** OgreWrapper for VotreProjet
**
** Made by pirou_g in /home/pirou_g/ClionProjects/VotreProjet
** Login   <pirou_g@epitech.net>
**
** Started on     03/04/16 11:31
** Last update on 03/04/16 11:31
*/

#ifndef CPP_ARCADE_OGREWRAPPER_HH
# define CPP_ARCADE_OGREWRAPPER_HH

# include <OgreCamera.h>
# include <OgreEntity.h>
# include <OgreLogManager.h>
# include <OgreRoot.h>
# include <OgreViewport.h>
# include <OgreSceneManager.h>
# include <OgreRenderWindow.h>
# include <OgreConfigFile.h>
# include <OIS/OISEvents.h>
# include <OIS/OISInputManager.h>
# include <OIS/OISKeyboard.h>
# include <OIS/OISMouse.h>
# include <SdkTrays.h>
# include <SdkCameraMan.h>
# include <map>
# include "IGui.hh"
# include "AEvents.hh"

# ifndef NULL
#  define NULL 0
# endif /* NULL */

class OgreWrapperGui : public Ogre::FrameListener,
                       public Ogre::WindowEventListener,
                       public OIS::KeyListener,
                       public OIS::MouseListener,
                       OgreBites::SdkTrayListener,
                       public IGui
{
public:
    OgreWrapperGui(void);
    virtual ~OgreWrapperGui();

    virtual void drawPixel(Point<int> const &point, Color<unsigned char> const &color);
    virtual void drawBuffer(Point<int> const &point, Buffer<unsigned char> const &buffer);
    virtual void render(void);
    virtual std::list<int>* getEvents(void) const;

    void go(void);

protected:
    virtual bool keyPressed(OIS::KeyEvent const &);
    virtual bool keyReleased(OIS::KeyEvent const &);
    virtual bool mouseMoved(OIS::MouseEvent const &);
    virtual bool mousePressed(OIS::MouseEvent const &, OIS::MouseButtonID id);
    virtual bool mouseReleased(OIS::MouseEvent const &, OIS::MouseButtonID id);
    virtual void windowClosed(Ogre::RenderWindow*);
    virtual bool frameRenderingQueued(Ogre::FrameEvent const &);

private:
    Ogre::Root* _root;
    Ogre::Camera* _camera;
    Ogre::SceneManager* _sceneManager;
    Ogre::RenderWindow* _window;
    Ogre::OverlaySystem* _overlaySystem;
    OgreBites::SdkTrayManager* _trayManager;
    OgreBites::SdkCameraMan* _cameraMan;
    OgreBites::ParamsPanel* _panel;
    OIS::InputManager* _inputManager;
    OIS::Mouse* _mouse;
    OIS::Keyboard* _keyboard;
    Ogre::String _resources;
    Ogre::String _plugins;
    OgreBites::InputContext _inputContext;
    std::map<int, int> _keys;
    std::map<int, int> _mouses;
    std::list<int> _eventsKeyboard;
    std::list<int> _eventsMouse;
    Ogre::BillboardSet* _billboardSet;
    Ogre::Billboard* _billboard;
    Ogre::TexturePtr _texture;
    std::uint8_t* _buffer;

    OgreWrapperGui(OgreWrapperGui const &);
    OgreWrapperGui& operator=(OgreWrapperGui const &);
};
#endif //CPP_ARCADE_OGREWRAPPER_HH
