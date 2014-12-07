(function (self) {
    var Utils = self.internal_require('ti.jsutils');
    var tabGroup = self.internal_require('ti.ui.tabgroup');

    var UI = { Windows: {} };

    UI.AlertDialog = self.TiUIAlertDialog;
    UI.Button = self.TiUIButton;
    UI.EmailDialog = self.TiUIEmailDialog;
    UI.ImageButton = self.TiUIImageButton;
    UI.Label = self.TiUILabel;
    UI.ScrollView = self.TiUIScrollView;
    UI.SearchBar = self.TiUISearchBar;
    UI.Slider = self.TiUISlider;
    UI.Switch = self.TiUISwitch;
    UI.Tab = tabGroup.Tab;
    UI.TabGroup = tabGroup.TabGroup;
    UI.View = self.TiUIView;
    UI.Window = self.TiUIWindow;
    UI.TableView = self.TiUITableView;
    UI.TableViewRow = self.TiUITableViewRow;
    UI.TextField = self.TiUITextField;
    UI.WebView = self.TiUIWebView;
    UI.ImageView = self.TiUIImageView;
    UI.Windows.ProgressBar = self.TiUIWindowsProgressBar;
    UI.Windows.ProgressRing = self.TiUIWindowsProgressRing;
    UI.Notification = self.TiUINotification;

    // Create the global alert function
    self.global.alert = function (_msg) {
        Ti.UI.createAlertDialog({
            title: 'Alert',
            message: _msg
        }).show();
    };

    UI.ScrollView.prototype.setContentHeight = function (_height) {
        this.__ti_private__.contentView.setHeight(_height);
    };
    UI.ScrollView.prototype.getContentHeight = function (_height) {
        return this.__ti_private__.contentView.getHeight();
    };
    UI.ScrollView.prototype.setContentWidth = function (_width) {
        this.__ti_private__.contentView.setWidth(_width);
    };
    UI.ScrollView.prototype.getContentWidth = function () {
        return this.__ti_private__.contentView.getWidth();
    };
    UI.ScrollView.prototype.add = function (_child) {
        this.__ti_private__.contentView.add(_child);
    };
    UI.ScrollView.prototype.setLayout = function (_layout) {
        if (_layout == 'horizontal') {
            this.__ti_private__.contentView.left = 0;
        } else if (_layout == 'vertical') {
            this.__ti_private__.contentView.top = 0;
        }
        this.__ti_private__.contentView.setLayout(_layout);
    };
    UI.ScrollView.prototype.getLayout = function (_layout) {
        return this.__ti_private__.contentView.getLayout();
    };
    UI.ScrollView.prototype.getContentView = function () {
        return this.__ti_private__.contentView;
    }
    UI.AlertDialog.prototype.setButtonNames = function (_btns) {
        if (!Array.isArray(_btns)) {
            throw new Error('AlertDialog setButtonNames must take an array');
        }
        var self = this;
        _btns.forEach(function (each) {
            self.addButton(each);
        });
    }
    UI.setBackgroundColor = function () { };

    Utils.addPropertiesToTiObject(UI.AlertDialog, {
        buttonNames: [true, true],
        title: [true, true],
        message: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.Windows.ProgressBar, {
        isIndeterminate: [true, true],
        max: [true, true],
        min: [true, true],
        showError: [true, true],
        showPaused: [true, true],
        value: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.Windows.ProgressRing, {
        isActive: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.EmailDialog, {
        barColor: [true, true],
        bccRecipients: [true, true],
        ccRecipients: [true, true],
        html: [true, true],
        messageBody: [true, true],
        subject: [true, true],
        toRecipients: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.Button, {
        title: [true, true]
    });
    /*
    Utils.addPropertiesToTiObject(UI.Hub, {
        header: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.HubSection, {
        header: [true, true],
        content: [true, true]
    });
    */
    Utils.addPropertiesToTiObject(UI.ImageButton, {
        title: [true, true],
        image: [true, true],
        font: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.Label, {
        ellipsize: [true, true],
        font: [true, true],
        highlightedColor: [true, true],
        text: [true, true],
        textAlign: [true, true],
        verticalAlign: [true, true],
        wordWrap: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.Notification, {
        duration: [true, true],
        //horizontalMargin: [true, true],
        message: [true, true],
        //verticalMargin: [true, true],
       // xOffset: [true, true],
        //yOffset: [true, true]
    });

    Utils.addPropertiesToTiObject(UI.Tab, {
        title: [true, true],
        window: [true, true],
        icon: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.TabGroup, {
        activeTab: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.TextField, {
        autocapitalization: [true, true],
        autocorrect: [true, true],
        borderStyle: [true, true],
        clearOnEdit: [true, true],
        color: [true, true],
        editable: [true, true],
        ellipsize: [true, true],
        enableReturnKey: [true, true],
        font: [true, true],
        hintText: [true, true],
        keyboardType: [true, true],
        maxLength: [true, true],
        passwordMask: [true, true],
        returnKeyType: [true, true],
        selection: [false, true],
        suppressReturn: [true, true],
        textAlign: [true, true],
        value: [true, true],
        verticalAlign: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.ScrollView, {
        canCancelEvents: [true, true],
        contentView: [false, true],
        contentHeight: [true, true],
        contentOffset: [true, true],
        contentWidth: [true, true],
        maxZoomScale: [true, true],
        minZoomScale: [true, true],
        scrollingEnabled: [true, true],
        showHorizontalScrollIndicator: [true, true],
        showVerticalScrollIndicator: [true, true],
        zoomScale: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.SearchBar, {
        autocapitalization: [true, true],
        autocorrect: [true, true],
        barColor: [true, true],
        enabled: [true, true],
        hintText: [true, true],
        hinttextid: [true, true],
        keyboardType: [true, true],
        prompt: [true, true],
        promptid: [true, true],
        showBookmark: [true, true],
        showCancel: [true, true],
        value: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.Switch, {
        color: [true, true],
        enabled: [true, true],
        font: [true, true],
        title: [true, true],
        titleOff: [true, true],
        titleOn: [true, true],
        value: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.Window, {
        exitOnClose: [true, true],
        flagSecure: [true, true],
        fullscreen: [true, true],
        modal: [true, true],
        navBarHidden: [true, true],
        orientation: [false, true],
        orientationModes: [true, true],
        statusBarStyle: [true, true],
        toolbar: [false, true],
        transitionAnimation: [true, true],
    });
    Utils.addPropertiesToTiObject(UI.TableView, {
        allowsSelection: [true, true],
        allowsSelectionDuringEditing: [true, true],
        data: [true, true],
        editable: [true, true],
        editing: [true, true],
        filterAnchored: [true, true],
        filterAttribute: [true, true],
        filterCaseInsensitive: [true, true],
        footerDividersEnabled: [true, true],
        footerTitle: [true, true],
        footerView: [true, true],
        headerDividersEnabled: [true, true],
        headerPullView: [true, true],
        headerTitle: [true, true],
        headerView: [true, true],
        hideSearchOnSelection: [true, true],
        index: [true, true],
        maxRowHeight: [true, true],
        minRowHeight: [true, true],
        moveable: [true, true],
        moving: [true, true],
        overScrollMode: [true, true],
        refreshControl: [true, true],
        rowHeight: [true, true],
        scrollIndicatorStyle: [true, true],
        scrollable: [true, true],
        search: [true, true],
        searchAsChild: [true, true],
        searchHidden: [true, true],
        sectionCount: [false, true],
        sections: [true, true],
        separatorColor: [true, true],
        separatorInsets: [true, true],
        separatorStyle: [true, true],
        showVerticalScrollIndicator: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.WebView, {
        cacheMode: [true, true],
        data: [true, true],
        disableBounce: [true, true],
        enableZoomControls: [true, true],
        handlePlatformUrl: [true, true],
        hideLoadIndicator: [true, true],
        html: [true, true],
        opacity: [true, true],
        ignoreSslError: [true, true],
        lightTouchEnabled: [true, true],
        loading: [false, true],
        onCreateWindow: [true, true],
        overScrollMode: [true, true],
        pluginState: [true, true],
        scalesPageToFit: [true, true],
        scrollsToTop: [true, true],
        showScrollbars: [true, true],
        url: [true, true],
        userAgent: [true, true],
        willHandleTouches: [true, true]
    });
    Utils.addPropertiesToTiObject(UI.ImageView, {
        animating: [true, true],
        autorotate: [true, true],
        decodeRetries: [true, true],
        defaultImage: [true, true],
        duration: [true, true],
        enableZoomControls: [true, true],
        hires: [true, true],
        image: [true, true],
        images: [true, true],
        paused: [true, true],
        preventDefaultImage: [true, true],
        repeatCount: [true, true],
        reverse: [true, true]
    });

    // Create the public API
    [
        'View', 'Window', 'Button', 'Slider', 'Label', 'EmailDialog',
        'AlertDialog', 'Switch', 'SearchBar', /*'Hub', 'HubSection',*/
        'Tab', 'TabGroup', 'ImageButton', 'TableView', 'TableViewRow',
        'ImageView', 'WebView', 'TextField', 'ProgressBar', 'ActivityIndicator',
        'Notification'

    ].forEach(function (_name) {
        UI['create' + _name] = function (_args) {
            var ui = new UI[_name]();
            ui.applyProperties(_args);
            return ui;
        }
    });

    // Ti.UI.Windows namespace types
    [
       'ProgressBar', 'ProgressRing'
    ].forEach(function (_name) {
        UI.Windows['create' + _name] = function (_args) {
            var ui = new UI.Windows[_name]();
            ui.applyProperties(_args);
            return ui;
        }
    });

    // Special case create* methods
    UI.createProgressBar = function(_args) {
        var view = UI.createView({
            layout: 'vertical',
            height: Ti.UI.SIZE
        });
        // TODO Given that Windows UI standards are to use a title, 10px vertical spacing, bar, 10px vertical spacing then message, maybe we should put bar first then label and set label's opacity to 0.8?
        view.__ti_private__.label = UI.createLabel({
            width: Ti.UI.FILL,
            height: Ti.UI.SIZE,
            font: {
                fontSize: 11, // should be 11pt, but our setFont doesn't handle units
                fontFamily: 'Segoe UI'
            },
            color: '#fff'
        });
        // Add 10px spacing between label and bar as per http://msdn.microsoft.com/en-us/library/windows/apps/xaml/hh465469.aspx
        view.__ti_private__.bar = UI.Windows.createProgressBar({
            color: '#fff',
            width: Ti.UI.FILL,
            height: Ti.UI.SIZE,
            top: 10
        });

        view.add(view.__ti_private__.label);
        view.add(view.__ti_private__.bar);
        view.hide();

        Utils.delegate(view, 'label', {
            color: [true, true],
            font: [true, false]
           // message: [true, true] // FIXME This is called 'text' on label...
        });
        Utils.delegate(view, 'bar', {
            max: [true, true],
            min: [true, true],
            value: [true, true]
        });
        // TODO Modify delegate to handle when composite calls property one thing and delegated controls calls it another (i.e. message -> label.text)
        // TODO Modify delegate to combine with addPropertiesToObject?
        view.setMessage = function (_msg) {
            this.__ti_private__.label.setText(_msg);
        }
        view.getMessage = function () {
            return this.__ti_private__.label.getText();
        }
        view.setStyle = function (_style) {
            // TODO Implement!
        }
        view.getStyle = function () {
            return undefined;
        }
        // order matters here. We must define the getters/setters first, before adding the properties
        Utils.addPropertiesToObject(view, {
            color: [true, true],
            font: [true, true],
            max: [true, true],
            message: [true, true],
            min: [true, true],
            style: [true, true],
            value: [true, true]
        });
        view.applyProperties(_args);

        return view;
    }

    UI.createActivityIndicator = function (_args) {
        var view = UI.createView({
            layout: 'horizontal',
            width: Ti.UI.SIZE,
            height: Ti.UI.SIZE
        });
        view.__ti_private__.ring = UI.Windows.createProgressRing({
            color: '#fff',
            backgroundColor: 'transparent'
        });
        view.__ti_private__.label = UI.createLabel({
            font: {
                fontSize: 20, // should be 11pt, but our setFont doesn't handle units
                fontFamily: 'Segoe UI'
            },
            color: '#fff', // FIXME The bottom of text should be aligned with bottom of ring!
            left: 5
        });
        view.add(view.__ti_private__.ring);
        view.add(view.__ti_private__.label);
        view.hide();

        Utils.delegate(view, 'label', {
            color: [true, true], // FIXME this doesn't seem to be getting delegated. Something is up here...
            font: [true, false]
        });
        view.setIndicatorColor = function (_color) {
            this.__ti_private__.ring.setColor(_color);
        }
        view.getIndicatorColor = function () {
            return this.__ti_private__.ring.getColor();
        }
        view.setIndicatorDiameter = function (_diameter) {
            this.__ti_private__.ring.setWidth(_diameter);
            this.__ti_private__.ring.setHeight(_diameter);
        }
        view.getIndicatorDiameter = function () {
            return this.__ti_private__.ring.getWidth();
        }
        view.setMessage = function (_msg) {
            this.__ti_private__.label.setText(_msg);
        }
        view.getMessage = function () {
            return this.__ti_private__.label.getText();
        }
        view.setStyle = function (_style) {
            // TODO Implement!
        }
        view.getStyle = function () {
            return undefined;
        }
        view.show = function () {
            this.__ti_private__.ring.show();
            UI.View.prototype.show.call(this);
        }
        view.hide = function () {
            this.__ti_private__.ring.hide();
            UI.View.prototype.hide.call(this);
        }
        // order matters here. We must define the getters/setters first, before adding the properties
        Utils.addPropertiesToObject(view, {
            indicatorColor: [true, true],
            indicatorDiameter: [true, true],
            message: [true, true],
            style: [true, true]
        });
        view.applyProperties(_args);

        return view;
    }

    UI.createScrollView = function (_args) {
        try {
            _args = _args || {};
            var ui = new UI.ScrollView();
            ui.__ti_private__.contentView = UI.createView({
                width: UI.SIZE,
                height: UI.SIZE,
                name: 'scrollView.contentView'
            });
            ui.setContentView(ui.__ti_private__.contentView);
            ui.applyProperties(_args);
            return ui;
        } catch (er) {
            console.log(er);
        }
    };
    return UI;
})(this);
