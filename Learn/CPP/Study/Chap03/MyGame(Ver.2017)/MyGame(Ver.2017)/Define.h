#pragma once

#define ERR_MSG(x, y, str) DoubleBuffer::GetInst()->WriteBuffer(x, y, str);
#define RAND rand()%2000 + 500