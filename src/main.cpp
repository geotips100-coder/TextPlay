
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        bool enabled =
            Mod::get()->getSettingValue<bool>("replace-play-button");

        if (!enabled) {
            return true;
        }

        auto menu = this->getChildByID("main-menu");

        if (!menu) {
            log::warn("TextPlay: main-menu not found");
            return true;
        }

        auto button = menu->getChildByID("play-button");

        if (!button) {
            log::warn("TextPlay: play-button not found");
            return true;
        }

        auto label = CCLabelBMFont::create("PLAY", "bigFont.fnt");

        if (!label) {
            return true;
        }

        label->setScale(0.8f);

        auto item = CCMenuItemSpriteExtra::create(
            label,
            this,
            menu_selector(MenuLayer::onPlay)
        );

        item->setPosition(button->getPosition());

        menu->addChild(item);

        button->setVisible(false);

        return true;
    }
};
