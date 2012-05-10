int nextEdge (int vertex, int direction) {
   /* 0 is right
   1 is right down
   2 is left down
   3 is left
   4 is left up
   5 is right up
   */
   int newVertex;
   if (direction == 0) {
      newVertex = right(vertex);
   } else if (direction == 1) {
      newVertex = rightDown(vertex);
   } else if (direction == 2) {
      newVertex = leftDown(vertex);
   } else if (direction == 3) {
      newVertex = left(vertex);
   } else if (direction == 4) {
      newVertex = leftUp(vertex);
   } else if (direction == 5) {
      newVertex = rightUp(vertex);
   }
   int edge;
   edge = (100 * vertex) + newVertex;
   return edge;
}

int right(int vertex) {
   int offset;
   if (vertex < 8) {
      offset = 8;
   } else if (vertex < 16) {
      offset = 10;
   } else if (vertex < 27) {
      offset = 11;
   } else if (vertex < 39){
      offset = 10;
   } else {
      offset = 8;
   }
   return vertex + offset;
}

int rightDown (vertex) {
   return (vertex + 1);
}

int leftDown (int vertex) {
   return (vertex + 1);
}

int left (int vertex) {
   int offset;
   if (vertex < 15) {
      offset = 8;
   } else if (vertex < 26) {
      offset = 10;
   } else if (vertex < 38) {
      offset = 11;
   } else if (vertex < 47){
      offset = 10;
   } else {
      offset = 8;
   }
   return (vertex - offset);
}

int leftUp (int vertex) {
   return (vertex - 1);
}

int rightUp (int vertex) {
   return (vertex - 1)
}
