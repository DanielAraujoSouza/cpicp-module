#include "../../include/common/converters.h"

double NapiValueToDouble(Napi::Value val)
{
  if (val.IsString())
  {
    return std::stod(val.As<Napi::String>().Utf8Value());
  }
  else
  {
    return val.As<Napi::Number>().DoubleValue();
  }
}

Point3 *NapiObjectToPoint3(Napi::Object pointObj)
{

  Point3 *point = new Point3(
      NapiValueToDouble(pointObj.Get("x")),
      NapiValueToDouble(pointObj.Get("y")),
      NapiValueToDouble(pointObj.Get("z")));

  return point;
}

Napi::Object Point3ToNapiObject(const Napi::Env env, Point3 *point)
{
  Napi::Object pointObj = Napi::Object::New(env);

  pointObj.Set("x", Napi::Number::New(env, point->Get('x')));
  pointObj.Set("y", Napi::Number::New(env, point->Get('y')));
  pointObj.Set("z", Napi::Number::New(env, point->Get('z')));

  return pointObj;
}

Cloud *NapiObjectToCloud(Napi::Object cloudObj)
{
  Cloud *cloud = new Cloud();
  Napi::Array points = cloudObj.Get("points").As<Napi::Array>();

  for (int i = 0; i < (int)points.Length(); i++)
  {
    cloud->AddPoint(NapiObjectToPoint3(points.Get(i).As<Napi::Object>()));
  }

  return cloud;
}

Napi::Object CloudToNapiObject(const Napi::Env env, Cloud *cloud)
{
  Napi::Array points = Napi::Array::New(env, cloud->Width());

  std::vector<Point3 *>::iterator it;
  std::vector<Point3 *> *pointsVect = cloud->Points();
  uint i = 0;
  for (it = pointsVect->begin(); it != pointsVect->end(); ++it)
  {
    points[i++] = Point3ToNapiObject(env, *it);
  }

  Napi::Object cloudObj = Napi::Object::New(env);
  cloudObj.Set("numpts", cloud->Width());
  cloudObj.Set("points", points);
  return (Napi::Object)cloudObj;
}