#include "../include/cpicp.h"

int partitionWidth(int cloudWidth, int numPartitions, int partitionIdx)
{
  if (partitionIdx > numPartitions || partitionIdx == 0)
  {
    return 0;
  }

  int floorWidth = floor(cloudWidth / numPartitions);
  int rest = cloudWidth - (floorWidth * numPartitions);

  return (partitionIdx <= rest ? floorWidth + 1 : floorWidth);
}

std::vector<Cloud *> *cloudPartitioning(Cloud *cloud, int numPartitions, char axis)
{

  cloud->SortByAxis(axis);

  std::vector<Cloud *> *partitionsVector = new std::vector<Cloud *>();

  int startOffset = 0;
  int endOffset = 0;

  for (int j = 1; j <= numPartitions; j++)
  {
    startOffset = endOffset;
    endOffset = startOffset + partitionWidth(cloud->Width(), numPartitions, j);

    std::vector<Point3 *> *partitionPoints = cloud->Points();
    Cloud *pCloud = new Cloud(new std::vector<Point3 *>(
        partitionPoints->begin() + startOffset,
        partitionPoints->begin() + endOffset));

    partitionsVector->push_back(pCloud);
  }

  return partitionsVector;
}