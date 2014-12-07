function TabGroup() {
    Object.defineProperty(this, "__ti_private__", {
        enumerable: false,
        value: {}
    });
    //var barHeight = 80; // TODO: make it dynamic?
    this.__ti_private__.window = Ti.UI.createWindow({
        name: 'tab_window',
        layout: 'vertical'
    });
    this.__ti_private__.bar = Ti.UI.createView({
        top: 0,
        height: Ti.UI.SIZE,
        backgroundColor: 'red',
        layout: 'horizontal',
        name: 'tabBar'
    });
    this.__ti_private__.content = Ti.UI.createScrollView({
        top: 0,
        bottom: 0,
        width: Ti.UI.FILL,
        contentWidth: Ti.UI.SIZE,
        name: 'scrollView',
        layout: 'horizontal',
        backgroundColor: '#ccc',
        scrollingEnabled: false,
        showHorizontalScrollIndicator: false,
        showVerticalScrollIndicator: false
    });
    this.__ti_private__.window.add(this.__ti_private__.bar);
    this.__ti_private__.window.add(this.__ti_private__.content);
    this.__ti_private__.index = 0;
    this.__ti_private__.windowWidth = 0;
    this.__ti_private__.tabs = [];
    var self = this;
    this.__ti_private__.window.addEventListener('postlayout', function (e) {
        self.__ti_private__.windowWidth = e.width;
        self.setActiveTab(self.__ti_private__.index);
    });
};
TabGroup.prototype.applyProperties = function (_args) {
    _args = _args || {};
    for (var key in _args) {
        this[key] = _args[key];
    }
};
TabGroup.prototype.setActiveTab = function (_n) {
    this.__ti_private__.index = _n;
    if (this.__ti_private__.windowWidth == 0) return;
    var self = this;
    setTimeout(function () {
        self.__ti_private__.content.scrollTo({
            x: self.__ti_private__.windowWidth * self.__ti_private__.index,
            animated: false // ???
        });
    }, 1);
}
TabGroup.prototype.open = function () {
    this.__ti_private__.window.open();
    this.setActiveTab(this.__ti_private__.index);
};
TabGroup.prototype.addTab = function (_tab) {
    var self = this;

    this.__ti_private__.bar.add(_tab.__ti_private__.title);
    this.__ti_private__.content.add(_tab.__ti_private__.window);
    var tabLength = this.__ti_private__.bar.children.length;
    var width = (1 / tabLength * 100) + '%';
    this.__ti_private__.bar.children.forEach(function (tab) {
        tab.width = width;
    });
    _tab.__ti_private__.title._index = tabLength - 1;
    _tab.__ti_private__.title.addEventListener('click', function (e) {
        self.setActiveTab(e.source._index);
    });

};

function Tab() {
    Object.defineProperty(this, "__ti_private__", {
        enumerable: false,
        value: {}
    });
    this.__ti_private__.window = null;
    this.__ti_private__.title = Ti.UI.createImageButton({
        height: Ti.UI.SIZE,
        left: 0, borderWidth: 0,
        font: {
            fontSize: 20
        }
    });
};
Tab.prototype.setWindow = function (_window) {
    this.__ti_private__.window = _window;
    this.__ti_private__.window.width = Ti.UI.FILL;
    this.__ti_private__.window.height = Ti.UI.FILL;
};
Tab.prototype.setTitle = function (_title) {
    this.__ti_private__.title.title = _title;
};
Tab.prototype.setIcon = function (_icon) {
    this.__ti_private__.title.image = _icon;
};
Tab.prototype.open = function (_window) {
    _window.open();
};
Tab.prototype.close = function (_window) {
    _window.close();
};
Tab.prototype.applyProperties = function (_args) {
    _args = _args || {};
    for (var key in _args) {
        this[key] = _args[key];
    }
};


exports.Tab = Tab;
exports.TabGroup = TabGroup;