#include <pluginlib/class_loader.hpp>
#include <polygon_base/regular_polygon.hpp>

int main(int argc, char** argv)
{
  // To avoid unused parameter warnings
  (void) argc;
  (void) argv;
 // The ClassLoader is the key class to understand, defined in the class_loader.hpp header
 // it is templated with the base class, i.e. polygon_base::RegularPolygon
 // The first argument is a string for the package name of the base class, i.e. polygon_base
 // The second argument is a string with the fully qualified base class type for the plugin, i.e. polygon_base::RegularPolygon
  pluginlib::ClassLoader<polygon_base::RegularPolygon> poly_loader("polygon_base", "polygon_base::RegularPolygon");

  try
  {
    // There are a number of ways to instantiate an instance of the class. In this example, we’re using shared pointers. 
    // We just need to call createSharedInstance with the fully-qualified type of the plugin class, in this case, polygon_plugins::Square
    std::shared_ptr<polygon_base::RegularPolygon> triangle = poly_loader.createSharedInstance("polygon_plugins::Triangle");
    triangle->initialize(10.0);

    std::shared_ptr<polygon_base::RegularPolygon> square = poly_loader.createSharedInstance("polygon_plugins::Square");
    square->initialize(10.0);

    printf("Triangle area: %.2f\n", triangle->area());
    printf("Square area: %.2f\n", square->area());
  }
  catch(pluginlib::PluginlibException& ex)
  {
    printf("The plugin failed to load for some reason. Error: %s\n", ex.what());
  }

  return 0;
}

// Important note: the polygon_base package in which this node is defined does NOT depend on the polygon_plugins class. 
// The plugins will be loaded dynamically without any dependency needing to be declared.
// Furthermore, we’re instantiating the classes with hardcoded plugin names, but you can also do so dynamically with parameters, etc.