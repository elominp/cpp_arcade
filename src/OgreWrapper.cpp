/*
** OgreWrapper for VotreProjet
**
** Made by pirou_g in /home/pirou_g/ClionProjects/VotreProjet
** Login   <pirou_g@epitech.net>
**
** Started on     03/04/16 11:41
** Last update on 03/04/16 11:41
*/

#include <stdexcept>
#include "OgreWrapper.hh"
#include "AEngine.hh"

OgreWrapperGui::OgreWrapperGui(void):
        _root(NULL),
        _camera(NULL),
        _sceneManager(NULL),
        _window(NULL),
        _overlaySystem(NULL),
        _trayManager(NULL),
        _cameraMan(NULL),
        _panel(NULL),
        _inputManager(NULL),
        _mouse(NULL),
        _keyboard(NULL)
{
    Ogre::ConfigFile conf;

    _resources = "resources.cfg";
    _plugins = "plugins.cfg";
    _root = new Ogre::Root(_plugins);

    conf.load(_resources);
    Ogre::ConfigFile::SectionIterator it = conf.getSectionIterator();
    Ogre::String section, type, arch;
    while (it.hasMoreElements())
    {
        section = it.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap* settings = it.getNext();
        for (auto it2 = settings->begin(); it2 != settings->end(); ++it2)
        {
            type = it2->first;
            arch = it2->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, section);
        }
    }

    if (_root->showConfigDialog())
        _window = _root->initialise(true, "cpp_arcade");
    else
        throw std::runtime_error("User doesn't want to play :'(");

    _sceneManager = _root->createSceneManager(Ogre::ST_GENERIC);
    _overlaySystem = new Ogre::OverlaySystem;
    _sceneManager->addRenderQueueListener(_overlaySystem);

    _camera = _sceneManager->createCamera("ArcadeCamera");
    _camera->setPosition(0, 0, 80);
    _camera->lookAt(0, 0, -300);
    _camera->setNearClipDistance(5);
    _cameraMan = new OgreBites::SdkCameraMan(_camera);

    Ogre::Viewport* port = _window->addViewport(_camera);
    port->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    OIS::ParamList list;
    std::size_t windowID = 0;
    _window->getCustomAttribute("WINDOW", &windowID);
    list.insert(std::make_pair("WINDOW", std::to_string(static_cast<std::size_t>(windowID))));
    _inputManager = OIS::InputManager::createInputSystem(list);
    _keyboard = static_cast<OIS::Keyboard*>(_inputManager->createInputObject(OIS::OISKeyboard, true));
    _mouse = static_cast<OIS::Mouse*>(_inputManager->createInputObject(OIS::OISMouse, true));
    _mouse->setEventCallback(this);
    _keyboard->setEventCallback(this);
    Ogre::WindowEventUtilities::addWindowEventListener(_window, this);
    _inputContext.mKeyboard = _keyboard;
    _inputContext.mMouse = _mouse;
    _trayManager = new OgreBites::SdkTrayManager("InterfaceName", _window, _inputContext, this);
    _trayManager->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    //_trayManager->hideCursor();
    _trayManager->hideAll();
    _root->addFrameListener(this);

    _keys.insert(std::pair<int, int> (OIS::KC_LEFT, AEvents::LEFT_ARROW));
    _keys.insert(std::pair<int, int> (OIS::KC_RIGHT, AEvents::RIGHT_ARROW));
    _keys.insert(std::pair<int, int> (OIS::KC_UP, AEvents::UP_ARROW));
    _keys.insert(std::pair<int, int> (OIS::KC_DOWN, AEvents::DOWN_ARROW));
    _keys.insert(std::pair<int, int> (OIS::KC_Q, AEvents::LEFT_ARROW));
    _keys.insert(std::pair<int, int> (OIS::KC_D, AEvents::RIGHT_ARROW));
    _keys.insert(std::pair<int, int> (OIS::KC_Z, AEvents::UP_ARROW));
    _keys.insert(std::pair<int, int> (OIS::KC_S, AEvents::DOWN_ARROW));
    _keys.insert(std::pair<int, int> (OIS::KC_SPACE, AEvents::SPACE));
    _keys.insert(std::pair<int, int> (OIS::KC_ESCAPE, AEvents::ESCAPE));
    _keys.insert(std::pair<int, int> (OIS::KC_RETURN, AEvents::ENTER));
    _keys.insert(std::pair<int, int> (OIS::KC_BACKSLASH, AEvents::BACKSPACE));
    _keys.insert(std::pair<int, int> (OIS::KC_4, AEvents::PREVIOUS_GAME));
    _keys.insert(std::pair<int, int> (OIS::KC_5, AEvents::NEXT_GAME));
    _keys.insert(std::pair<int, int> (OIS::KC_2, AEvents::PREVIOUS_GRAPHIC));
    _keys.insert(std::pair<int, int> (OIS::KC_3, AEvents::NEXT_GRAPHIC));
    _keys.insert(std::pair<int, int> (OIS::KC_8, AEvents::RESTART_GAME));
    _keys.insert(std::pair<int, int> (OIS::KC_9, AEvents::MENU));

    _mouses.insert(std::pair<int, int> (OIS::MB_Left, AEvents::LEFT_CLICK));
    _mouses.insert(std::pair<int, int> (OIS::MB_Right, AEvents::RIGHT_CLICK));
    _mouses.insert(std::pair<int, int> (OIS::MB_Middle, AEvents::MIDDLE_CLICK));

    _buffer = new std::uint8_t[((MAP_HEIGHT * MAP_TILE) * (MAP_WIDTH * MAP_TILE)) * 3];
    _texture = Ogre::TextureManager::getSingleton().createManual("GameTexture",
                                                                 Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                                                 Ogre::TEX_TYPE_2D,
                                                                 MAP_WIDTH * MAP_TILE,
                                                                 MAP_HEIGHT * MAP_TILE, 0,
                                                                 Ogre::PF_BYTE_RGBA,
                                                                 Ogre::TU_DEFAULT);
    Ogre::HardwarePixelBufferSharedPtr textureBuffer = _texture->getBuffer();
    textureBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    Ogre::PixelBox const &box = textureBuffer->getCurrentLock();
    std::uint8_t* ptr = static_cast<std::uint8_t*>(box.data);
    for (int i = 0; i < MAP_HEIGHT * MAP_TILE; i++)
    {
        for (int j = 0; j < MAP_WIDTH * MAP_TILE; j++)
        {
            _buffer[(i * MAP_WIDTH * MAP_TILE)] = 0;
            _buffer[(i * MAP_WIDTH * MAP_TILE) + 1] = 0;
            _buffer[(i * MAP_WIDTH * MAP_TILE) + 2] = 0;
            *(ptr++) = 255;
            *(ptr++) = 255;
            *(ptr++) = 255;
            *(ptr++) = 255;
        }
        ptr += box.getRowSkip() * Ogre::PixelUtil::getNumElemBytes(box.format);
    }
    textureBuffer->unlock();
    Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Background",
                                                                              Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    material->getTechnique(0)->getPass(0)->createTextureUnitState("GameTexture");

    _billboardSet = _sceneManager->createBillboardSet();
    _billboard = _billboardSet->createBillboard(Ogre::Vector3(0, 0, -50));
    _billboardSet->setMaterial(material);
    _sceneManager->getRootSceneNode()->attachObject(_billboardSet);

    Ogre::Light* light = _sceneManager->createLight("MainLight");
    light->setPosition(0, 0, 0);
}

OgreWrapperGui::~OgreWrapperGui()
{
    delete[] _buffer;
    if (_trayManager != NULL)
        delete _trayManager;
    if (_cameraMan != NULL)
        delete _cameraMan;
    if (_overlaySystem != NULL)
        delete _overlaySystem;
    Ogre::WindowEventUtilities::removeWindowEventListener(_window, this);
    if (_inputManager != NULL)
    {
        _inputManager->destroyInputObject(_mouse);
        _inputManager->destroyInputObject(_keyboard);
        OIS::InputManager::destroyInputSystem(_inputManager);
    }
    delete _root;
}

bool OgreWrapperGui::keyPressed(const OIS::KeyEvent &event) {
    _eventsKeyboard.push_back(_keys[event.key]);
    return true;
}

bool OgreWrapperGui::keyReleased(const OIS::KeyEvent &event) {
    return true;
}

bool OgreWrapperGui::mouseMoved(const OIS::MouseEvent &event) {
    _cameraMan->injectMouseMove(event);
    return true;
}

bool OgreWrapperGui::mousePressed(const OIS::MouseEvent &event, OIS::MouseButtonID id) {
    _eventsMouse.push_back(_mouses[id]);
    _cameraMan->injectMouseDown(event, id);
    return true;
}

bool OgreWrapperGui::mouseReleased(const OIS::MouseEvent &event, OIS::MouseButtonID id) {
    _cameraMan->injectMouseUp(event, id);
    return true;
}

void OgreWrapperGui::drawPixel(Point<int> const &point, Color<unsigned char> const &color)
{
    if (point.getX() < 0 || point.getX() >= (MAP_WIDTH * MAP_TILE) ||
        point.getY() < 0 || point.getY() >= (MAP_HEIGHT * MAP_TILE))
        return;
    Ogre::HardwarePixelBufferSharedPtr textureBuffer = _texture->getBuffer();
    textureBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    Ogre::PixelBox const &box = textureBuffer->getCurrentLock();
    std::uint8_t* ptr = static_cast<std::uint8_t*>(box.data);
    ptr += (point.getY() * ((MAP_WIDTH * MAP_TILE) * 4) +
            (box.getRowSkip() * Ogre::PixelUtil::getNumElemBytes(box.format))) +
            (point.getX() * 4);
    ptr[0] = color.getRed();
    ptr[1] = color.getGreen();
    ptr[2] = color.getBlue();
    ptr[3] = 255;
    textureBuffer->unlock();
}

void OgreWrapperGui::drawBuffer(Point<int> const &point, Buffer<unsigned char> const &buffer)
{
    int py = point.getY();
    int px = point.getX();
    if (px < 0 || px > (MAP_WIDTH * MAP_TILE) ||
        py < 0 || py > (MAP_HEIGHT * MAP_TILE) ||
        (py + buffer.getHeight()) > (MAP_HEIGHT * MAP_TILE) ||
        (px + buffer.getWidth()) > (MAP_TILE * MAP_WIDTH))
        return;
    for (std::size_t i = 0; i < buffer.getHeight(); i++)
    {
        for (std::size_t j = 0; j < buffer.getWidth(); j++)
        {
            Color<unsigned char> tmp = buffer.getPixel(j, i);
            _buffer[(((py + i) * (MAP_WIDTH * MAP_TILE)) + px + j) * 3] = tmp.getBlue();
            _buffer[(((py + i) * (MAP_WIDTH * MAP_TILE)) + px + j) * 3 + 1] = tmp.getGreen();
            _buffer[(((py + i) * (MAP_WIDTH * MAP_TILE)) + px + j) * 3 + 2] = tmp.getRed();
        }
    }
}

void OgreWrapperGui::render()
{
    _root->renderOneFrame();
    Ogre::HardwarePixelBufferSharedPtr textureBuffer = _texture->getBuffer();
    textureBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    Ogre::PixelBox const &box = textureBuffer->getCurrentLock();
    std::uint8_t* ptr = static_cast<std::uint8_t*>(box.data);
    for (int i = 0; i < MAP_HEIGHT * MAP_TILE; i++)
    {
        for (int j = 0; j < MAP_WIDTH * MAP_TILE; j++)
        {
            *(ptr++) = _buffer[((i * MAP_WIDTH * MAP_TILE) + j) * 3];
            *(ptr++) = _buffer[((i * MAP_WIDTH * MAP_TILE) + j) * 3 + 1];
            *(ptr++) = _buffer[((i * MAP_WIDTH * MAP_TILE) + j) * 3 + 2];
            *(ptr++) = 255;
        }
        ptr += box.getRowSkip() * Ogre::PixelUtil::getNumElemBytes(box.format);
    }
    textureBuffer->unlock();
}

std::list<int>* OgreWrapperGui::getEvents() const
{
    std::list<int> *events = new std::list<int>;
    for (auto it = _eventsKeyboard.cbegin(); it != _eventsKeyboard.cend(); it++)
        events->push_back(*it);
    for (auto it = _eventsMouse.cbegin(); it != _eventsMouse.cend(); it++)
        events->push_back(*it);
    return events;
}

void OgreWrapperGui::go()
{
    _root->startRendering();
}

void OgreWrapperGui::windowClosed(Ogre::RenderWindow* window)
{
    if (window == _window)
    {
        if (_inputManager != NULL)
        {
            _inputManager->destroyInputObject(_mouse);
            _inputManager->destroyInputObject(_keyboard);
            OIS::InputManager::destroyInputSystem(_inputManager);
            _inputManager = NULL;
        }
    }
}

bool OgreWrapperGui::frameRenderingQueued(const Ogre::FrameEvent &event)
{
    if (_window->isClosed())
        return false;
    _keyboard->capture();
    _mouse->capture();
    _trayManager->frameRenderingQueued(event);
    _cameraMan->frameRenderingQueued(event);
    return true;
}

IGui* Init(void)
{
    IGui* gui = new OgreWrapperGui;
    return gui;
}