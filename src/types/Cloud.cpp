#include "../../include/types/Cloud.h"

Cloud::Cloud(std::vector<Point3 *> *newPoints) : numpts(newPoints->size()), points(newPoints){};

Cloud::Cloud() : numpts(0), points(new std::vector<Point3 *>()){};

Cloud::~Cloud()
{
  std::vector<Point3 *>::iterator it;
  for (it = points->begin(); it != points->end(); ++it)
  {
    delete *it;
  }
  delete points;
};

void Cloud::AddPoint(Point3 *newPoint)
{
  points->push_back(newPoint);
  numpts += 1;
}

int Cloud::Width()
{
  return numpts;
}

std::vector<Point3 *> *Cloud::Points()
{
  return points;
};

void Cloud::SortByAxis(char axis)
{

  std::sort(points->begin(), points->end(), [&, axis](Point3 *a, Point3 *b)
            { return (a->Get(axis) < b->Get(axis)); });
}