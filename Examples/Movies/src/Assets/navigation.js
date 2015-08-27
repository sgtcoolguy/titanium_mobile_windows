function Navigation(_args) {
    var that = this;
    _args = _args || {};
    this.parent = _args.parent;
    this.controllers = [], this.currentController = null;
    this.currentControllerArguments = {};
    this.push = function(_controller, _controllerArguments) {
        if ("string" == typeof _controller) var controller = Alloy.createController(_controller, _controllerArguments); else var controller = _controller;
        that.currentController = controller;
        that.currentControllerArguments = _controllerArguments;
        that.controllers.push(controller);
        controller.window.open();
        return controller;
    }, this.pop = function() {
        var controller = that.controllers.pop();
        var window = controller.window;
        window.close();
        controller.destroy();
    }, this.openModal = function(_controller, _controllerArguments) {
        var controller = Alloy.createController(_controller, _controllerArguments);
        that.currentController = controller;
        that.currentControllerArguments = _controllerArguments;
        controller.window.addEventListener("open", function() {
            that.setActionBarStyle(controller.window);
        });
        controller.window.open();
        return controller;
    }, this.closeModal = function(_controller) {
        _controller.window.close();
        _controller.window = null;
        _controller.destroy();
        _controller = null;
    };
}

module.exports = function(_args) {
    return new Navigation(_args);
};