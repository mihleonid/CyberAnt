#include <list>
#include <math.h>
#include <cmath>
#include <algorithm>
#include "field.h"

Field::Field(){
	for(int i=0;i<BlocksX*BlocksY;i++){
		field[i]=nullptr;
	}
}


const FO* Field::get(int x, int y) const{
	return (const FO*)(field[y*BlocksX+x]);
}
const FO* Field::get(const Point& p) const{
	return (const FO*)get(p.getX(), p.getY());
}

FO* Field::get(int x, int y){
	return field[y*BlocksX+x];
}
FO* Field::get(const Point& p){
	return get(p.getX(), p.getY());
}

FO* Field::remove(const Point& p){
	return remove(p.getX(), p.getY());
}
FO* Field::remove(int x, int y){
	int i=y*BlocksX+x;
	FO* cur=field[i];

	int uo=all.remove(cur->order); // Номер того, кого хотим обновить
	(all[uo])->order=uo;
	
	field[i]=nullptr;
	return cur;
}
void Field::removeAll(){
	for(int x=0;x<BlocksX;++x){
		for(int y=0;y<BlocksY;++y){
			if(field[y*BlocksX+x]!=nullptr){
				delete remove(x, y);
			}
		}
	}
}

void Field::set(FO* f) {
	int i=(f->getPos().getY())*BlocksX+(f->getPos().getX());
	int o=f->order;
	if((o>=0)&&(o<all.size())){
		if(all[o]==f){
			goto ef;
		}
	}
	f->order=all.push(f);
	ef:;
	field[i]=f;
}

Path Field::getnb(const Point& p){
	return getnb(p.getX(), p.getY());
}
Path Field::getnb(int x, int y) {
	Path result;
	if(x==0){
		//((x|x+1), **)
		if(y==0){
			//((x|x+1), (y|y+1))
			result.push_back(Point(0, 1));//x, y+1
			result.push_back(Point(1, 0));//x+1, y
			result.push_back(Point(1, 1));//x+1, y+1
		}else{
			//(x|x+1, y-1|y|(y+1 ?))
			if(y==BlocksY-1){
				//(x|x+1, y-1|y)
				result.push_back(Point(0, y-1));//x, y-1
				result.push_back(Point(1, y-1));//x+1, y-1
				result.push_back(Point(1, y));//x+1, y
			}else{
				//(x|x+1, y-1|y|y+1)
				result.push_back(Point(0, y-1));//x, y-1
				result.push_back(Point(0, y+1));//x, y+1
				result.push_back(Point(1, y-1));//x+1, y-1
				result.push_back(Point(1, y));//x+1, y
				result.push_back(Point(1, y+1));//x+1, y+1
			}
		}
	}else{
		//(x-1|x|(x+1 ?), **)
		if(x==BlocksX-1){
			//(x-1|x, **)
			if(y==0){
				//(x-1|x, y|y+1)
				result.push_back(Point(x-1, 0));//x-1, y
				result.push_back(Point(x, 1));//x, y+1
				result.push_back(Point(x-1, 1));//x-1, y+1
			}else{
				//(x-1|x, y-1|y|(y+1 ?))
				if(y==BlocksY-1){
					//(x-1|x, y-1|y)
					result.push_back(Point(x-1, y-1));
					result.push_back(Point(x, y-1));
					result.push_back(Point(x-1, y));
				}else{
					//(x-1|x, y-1|y|y+1)
					result.push_back(Point(x-1, y-1));
					result.push_back(Point(x, y-1));
					result.push_back(Point(x-1, y));
					result.push_back(Point(x-1, y+1));
					result.push_back(Point(x, y+1));
				}
			}
		}else{
			//(x-1|x|x+1, **)
			if(y==0){
				//((x-1|x|x+1), (y|y+1))
				result.push_back(Point(x-1, 0));//x-1, y
				result.push_back(Point(x-1, 1));//x-1, y+1
				result.push_back(Point(x, 1));//x, y+1
				result.push_back(Point(x+1, y));//x+1, y
				result.push_back(Point(x+1, 1));//x+1, y+1
			}else{
				//(x-1|x|x+1, y-1|y|(y+1 ?))
				if(y==BlocksY-1){
					//(x-1|x|x+1, y-1|y)
					result.push_back(Point(x-1, y-1));
					result.push_back(Point(x, y-1));
					result.push_back(Point(x+1, y-1));
					result.push_back(Point(x-1, y));
					result.push_back(Point(x+1, y));
				}else{
					//(x-1|x|x+1, y-1|y|y+1)
					result.push_back(Point(x, y-1));
					result.push_back(Point(x+1, y-1));
					result.push_back(Point(x+1, y));
					result.push_back(Point(x+1, y+1));
					result.push_back(Point(x, y+1));
					result.push_back(Point(x-1, y+1));
					result.push_back(Point(x-1, y));
					result.push_back(Point(x-1, y-1));
				}
			}
		}
	}
	return result;
}

XStackIterator<FO*> Field::begin(){
	return XStackIterator<FO*>(&all);
}

class Node { //этот класс нужен только здесь, и я не знаю, где его определять
    public :
	int x, y; //где находится клетка
	int px, py; //откуда мы в нее пришли
	int total, G, H; //веса: G - сколько мы уже прошли, H - сколько мы должны пройти до кнечной точки, total = G+H
	Node( int x_, int y_, int px_, int py_ ) :
            x(x_), y(y_), px(px_), py(py_)
        {
        }
};

/*
Path Field::findPath(const Point& a, const Point& b){
	return findPath(a.getX(), a.getY(), b.getX(), b.getY());
}
Path Field::findPath( int x, int y, int tx, int ty ) {
	std::list<Node> open; //лист всех соседей
        std::list<Node> closed; //лист всех, кого мы проверили
        Node origin( x, y, tx, ty );
        open.push_back( origin ); //добавляем начальную вершину
        
        while(true) {
            if( open.empty() ) throw "Cannot find path"; //если ничего не осталось, выходим
            // находим клетку с минимальным весом
            Node* current = &open.front();
            auto it = open.begin();
            for ( ; it != open.end(); it++ ) {
                if ( it -> total < current -> total ) current = &*it;
            }
            
            open.erase(it); // удаляем клетку из соседей и добавляем в проверенные
            closed.push_back(*it);
            
            if ( current -> x == tx && current -> y == ty ) { //если достигли цели, то выйти из цикла
                break;
            }
            
            //проверяем всех соседей//
            auto neighbours = getnb( current -> x, current -> y );
            for ( auto neigh = neighbours.begin();
                 neigh != neighbours.end(); neigh++ ) {
                //проверяем, что мы ее еще не проверили
		// Сосед всегда на поле.
                // TODO проверяем, что сосед на поле
                //if ( neigh -> first < 0 || neigh -> first >= width || neigh -> second < 0 || neigh -> second > height ) continue;
                //проверяем, что там ничего нет
                if ( get( neigh -> first, neigh -> first ) != nullptr ) continue;
                //вычисляем веса
                int G = current -> G + 1;
                int H = std::max(std::abs(neigh -> first - tx), std::abs(neigh -> first - ty)); //подсчет расстояния очень плохой, TODO доделать
                //int H = (int)sqrt((double)((neigh->first-tx)*(neigh->first-tx)+(neigh->second-ty)*(neigh->second-ty)));
                int total = G + H;
                //ищем соседа в open
                auto node = 
                    std::find_if( open.begin(), open.end(), [neigh](Node n){
                        return n.x == neigh -> first && n.y == neigh -> second;
                    } );
                //если не нашли в open и в closed,
                if ( node != open.end() ) {
                    if ( !std::any_of( closed.begin(), closed.end(), [neigh](Node n){
                        return n.x == neigh -> first && n.y == neigh -> second;
                    }) ) {
                        //то добавляем клетку в open (мы нашли нового соседа)
                        Node newNode( neigh -> first, neigh -> second, current -> x, current -> y );
                        newNode.G = G;
                        newNode.H = H;
                        newNode.total = total;
                        open.push_back( newNode );
                    }
                } else if ( node -> G > G ) { //если не нашли в open, и вес клетки больше, чем вычисленный,
                    //то приравнять вес этой клетке
                    node -> G = G;
                }
            }
        }
        //после строим путь
        Path result;
        auto resultNode = std::find_if( closed.begin(), closed.end(), [tx, ty](Node n){ return n.x == tx && n.y == ty; } );
        while ( resultNode -> x != x && resultNode -> y != y ) {
            result.push_back( Point( resultNode -> x, resultNode -> y ) );
            resultNode = std::find_if( closed.begin(), closed.end(), 
                [resultNode](Node n){ return n.x == resultNode -> px && n.y == resultNode -> py; } );
        }
        std::reverse( result.begin(), result.end() );
        return result;
}
*/

