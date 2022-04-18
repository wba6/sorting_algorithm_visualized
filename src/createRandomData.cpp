

#include "createRandomData.h"
#include "SDL.h"

class randomData{
public:
  randomData(SDL_Renderer** render);

  ~randomData();
private:
  SDL_Renderer** rend;
  size_t rectLimit;
};