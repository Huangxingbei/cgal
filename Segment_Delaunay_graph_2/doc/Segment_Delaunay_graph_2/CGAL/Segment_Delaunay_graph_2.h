
namespace CGAL {

/*!
\ingroup PkgSegmentDelaunayGraph2

The class `Segment_Delaunay_graph_2` represents the segment Delaunay graph (which is 
the dual graph of the 2D segment Voronoi diagram). 
Currently it supports only insertions of sites. 
It is templated by two template arguments `Gt`, which 
must be a model of `SegmentDelaunayGraphTraits_2` 
and `DS`, 
which must be a model of `SegmentDelaunayGraphDataStructure_2`. 
The second template argument defaults to 
`CGAL::Triangulation_data_structure_2< CGAL::Segment_Delaunay_graph_vertex_base_2<Gt>, CGAL::Triangulation_face_base_2<Gt> >`. 

Traversal of the Segment Delaunay Graph 
-------------- 

A segment Delaunay graph can be seen as a container of faces and 
vertices. Therefore the `Segment_Delaunay_graph_2` class provides several iterators 
and circulators that allow to traverse it (completely or partially). 

Traversal of the Convex Hull 
----------------------------

Applied on the `infinite_vertex` the above methods allow to visit
the vertices on the convex hull and the infinite edges and
faces. Note that a counterclockwise traversal of the vertices
adjacent to the `infinite_vertex` is a clockwise traversal of the
convex hull. 

\code
CGAL::Segment_Delaunay_graph_2<Gt, DS> sdg;
CGAL::Segment_Delaunay_Graph_2<Gt, DS>::Face_handle f;
sdg.incident_vertices(sdg.infinite_vertex()); 
sdg.incident_vertices(sdg.infinite_vertex(), f); 
sdg.incident_faces(sdg.infinite_vertex()); 
sdg.incident_faces(sdg.infinite_vertex(), f); 
sdg.incident_edges(sdg.infinite_vertex()); 
sdg.incident_edges(sdg.infinite_vertex(), f); 
\endcode

\models ::DelaunayGraph_2 

\sa `DelaunayGraph_2` 
\sa `SegmentDelaunayGraphTraits_2` 
\sa `SegmentDelaunayGraphDataStructure_2` 
\sa `SegmentDelaunayGraphVertexBase_2` 
\sa `TriangulationFaceBase_2` 
\sa `CGAL::Segment_Delaunay_graph_hierarchy_2<Gt,STag,DS>` 
\sa `CGAL::Segment_Delaunay_graph_traits_2<K,MTag>` 
\sa `CGAL::Segment_Delaunay_graph_traits_without_intersections_2<K,MTag>` 
\sa `CGAL::Segment_Delaunay_graph_filtered_traits_2<CK,CM,EK,EM,FK,FM>` 
\sa `CGAL::Segment_Delaunay_graph_filtered_traits_without_intersections_2<CK,CM,EK,EM,FK,FM>` 
\sa `CGAL::Triangulation_data_structure_2<Vb,Fb>` 
\sa `CGAL::Segment_Delaunay_graph_vertex_base_2<Gt,SSTag>` 
\sa `CGAL::Triangulation_face_base_2<Gt>` 

*/
template< typename Gt, typename DS >
class Segment_Delaunay_graph_2 {
public:

/// \name Types 





/// @{

/*! 
A type for the geometric traits. 
*/ 
typedef Gt Geom_traits; 

/*! 
A type for the underlying 
data structure. 
*/ 
typedef DS Data_structure; 

/*! 
This type has been added so that the `Segment_Delaunay_graph_2` class is a model of 
the `DelaunayGraph_2` concept. 
*/ 
typedef Data_structure Triangulation_data_structure; 

/*! 
Size type (an unsigned integral type) 
*/ 
typedef typename DS::size_type size_type; 

/*! 
A type for the 
point defined in the geometric traits. 
*/ 
typedef typename Gt::Point_2 Point_2; 

/*! 
A type for the segment Delaunay graph site, defined in the geometric 
traits. 
*/ 
typedef typename Gt::Site_2 Site_2; 

/*! 
A type for the container of points. 
*/ 
typedef Hidden_type Point_container; 

/*! 
A handle for points in the point container. 
*/ 
typedef typename Point_container::iterator Point_handle; 

/// @}

/// \name Iterators and Handles
/// The vertices and faces of the segment Delaunay graph are accessed
/// through `handles`, `iterators` and `circulators`. The iterators
/// and circulators are all bidirectional and non-mutable. The
/// circulators and iterators are assignable to the corresponding
/// handle types, and they are also convertible to the corresponding
/// handles. The edges of the segment Delaunay graph can also be
/// visited through iterators and circulators, the edge circulators
/// and iterators are also bidirectional and non-mutable. In the
/// following, we call <I>infinite</I> any face or edge incident to
/// the infinite vertex and the infinite vertex itself. Any other
/// feature (face, edge or vertex) of the segment Delaunay graph is
/// said to be <I>finite</I>. Some iterators (the `All` iterators )
/// allow to visit finite or infinite features while the others (the
/// `Finite` iterators) visit only finite features. Circulators visit
/// both infinite and finite features.

/// @{

/*! 
The edge type. 
The `Edge(f,i)` is the edge common to faces `f` and 
`f.neighbor(i)`. It is also the edge joining the vertices 
`vertex(cw(i))` and `vertex(ccw(i))` of `f`. 
\pre `i` must be `0`, `1` or `2`. 
*/ 
typedef typename DS::Edge Edge; 

/*! 
A type for a vertex. 
*/ 
typedef typename DS::Vertex Vertex; 

/*! 
A type for a face. 
*/ 
typedef typename DS::Face Face; 

/*! 
A type for a handle to a vertex. 
*/ 
typedef typename DS::Vertex_handle Vertex_handle; 

/*! 
A type for a handle to a face. 
*/ 
typedef typename DS::Face_handle Face_handle; 

/*! 
A type for a circulator over vertices incident to a given vertex. 
*/ 
typedef typename DS::Vertex_circulator Vertex_circulator; 

/*! 
A type for a circulator over faces incident to a given vertex. 
*/ 
typedef typename DS::Face_circulator Face_circulator; 

/*! 
A type for a circulator over edges incident to a given vertex. 
*/ 
typedef typename DS::Edge_circulator Edge_circulator; 

/*! 
A type for an iterator over all vertices. 
*/ 
typedef typename DS::Vertex_iterator All_vertices_iterator; 

/*! 
A type for an iterator over all faces. 
*/ 
typedef typename DS::Face_iterator All_faces_iterator; 

/*! 
A type for an iterator over all edges. 
*/ 
typedef typename DS::Edge_iterator All_edges_iterator; 

/*! 
A type for an iterator over finite vertices. 
*/ 
typedef Hidden_type Finite_vertices_iterator; 

/*! 
A type for an iterator over finite faces. 
*/ 
typedef Hidden_type Finite_faces_iterator; 

/*! 
A type for an iterator over finite edges. 
*/ 
typedef Hidden_type Finite_edges_iterator; 

/// @}

/// \name Site Iterators
/// In addition to iterators and circulators for vertices and faces,
/// iterators for sites are provided. In particular there are
/// iterators for the set of input sites and the set of output
/// sites. The set of input sites is the set of sites inserted by the
/// user using the `insert` methods of this class. If a site is
/// inserted multiple times, every instance of this site will be
/// reported. The set of output sites is the set of sites in the
/// segment Delaunay graph. The value type of these iterators is
/// `Site_2`.
/// @{

/*! 
A type for a bidirectional iterator over all input sites. 
*/ 
typedef Hidden_type Input_sites_iterator; 

/*! 
A type for a bidirectional iterator over all output sites (the sites 
in the Delaunay graph). 
*/ 
typedef Hidden_type Output_sites_iterator; 

/// @} 

/// \name Creation 
/// In addition to the default and copy constructors the following
/// constructors are defined:
/// @{

/*! 
Creates the 
segment Delaunay graph using `gt` as geometric traits. 
*/ 
Segment_Delaunay_graph_2(Gt gt=Gt()); 

/*! 
Creates the segment Delaunay graph using `gt` as geometric traits 
and inserts all sites in the range [`first`, `beyond`). 
\pre `Input_iterator` must be a model of `InputIterator`. The value type of `Input_iterator` must be either `Point_2` or `Site_2`. 
*/ 
template< class Input_iterator > 
Segment_Delaunay_graph_2(Input_iterator first, Input_iterator beyond, 
Gt gt=Gt()); 

/// @} 

/// \name Access Functions 
/// @{

/*! 
Returns a reference to the segment Delaunay graph traits object. 
*/ 
Geom_traits geom_traits(); 

/*! 
Returns the dimension of the segment Delaunay graph. The dimension 
is \f$ -1\f$ if the graph contains no sites, \f$ 0\f$ if the graph 
contains one site, \f$ 1\f$ if it contains two sites and \f$ 2\f$ if it 
contains three or more sites. 
*/ 
int dimension(); 

/*! 
Returns the number of finite vertices of the segment Delaunay graph. 
*/ 
size_type number_of_vertices(); 

/*! 
Returns the number of faces (both finite and infinite) of the 
segment Delaunay graph. 
*/ 
size_type number_of_faces(); 

/*! 
Return the number of input sites. 
*/ 
size_type number_of_input_sites(); 

/*! 
Return the number of output sites. This is equal to the number of 
vertices in the segment Delaunay graph. 
*/ 
size_type number_of_output_sites(); 

/*! 
Returns a face incident to the `infinite_vertex`. 
*/ 
Face_handle infinite_face(); 

/*! 
Returns the `infinite_vertex`. 
*/ 
Vertex_handle 
infinite_vertex(); 

/*! 
Returns a vertex distinct from the `infinite_vertex`. 
\pre The number of sites in the segment Delaunay graph must be at least one. 
*/ 
Vertex_handle finite_vertex(); 

/*! 
Returns a reference to the 
segment Delaunay graph data structure object. 
*/ 
Data_structure data_structure(); 

/*! 
Same as `data_structure()`. It 
has been added for compliance to the `DelaunayGraph_2` concept. 
*/ 
Data_structure tds(); 

/*! 
Returns a reference to 
the point container object. 
*/ 
Point_container point_container(); 

/// @} 

/// \name Finite Face, Edge and Vertex Iterators 
/// The following iterators allow respectively to visit finite faces,
/// finite edges and finite vertices of the segment Delaunay
/// graph. These iterators are non-mutable, bidirectional and their
/// value types are respectively `Face`, `Edge` and `Vertex`. They are
/// all invalidated by any change in the segment Delaunay graph.
/// @{

/*! 
Starts at an arbitrary finite vertex. 
*/ 
Finite_vertices_iterator finite_vertices_begin(); 

/*! 
Past-the-end iterator. 
*/ 
Finite_vertices_iterator finite_vertices_end(); 

/*! 
Starts at an arbitrary finite edge. 
*/ 
Finite_edges_iterator finite_edges_begin(); 

/*! 
Past-the-end iterator. 
*/ 
Finite_edges_iterator finite_edges_end(); 

/*! 
Starts at an arbitrary finite face. 
*/ 
Finite_faces_iterator finite_faces_begin(); 

/*! 
Past-the-end iterator. 
*/ 
Finite_faces_iterator finite_faces_end() 
const; 


/// \name Infinite Face, Edge, and Vertex Iterators
/// The following iterators allow respectively to visit all (both
/// finite and infinite) faces, edges and vertices of the segment
/// Delaunay graph. These iterators are non-mutable, bidirectional and
/// their value types are respectively `Face`, `Edge` and
/// `Vertex`. They are all invalidated by any change in the segment
/// Delaunay graph.
/// @{

/*! 
Starts at an arbitrary vertex. 
*/ 
All_vertices_iterator all_vertices_begin(); 

/*! 
Past-the-end iterator. 
*/ 
All_vertices_iterator all_vertices_end(); 

/*! 
Starts at an arbitrary edge. 
*/ 
All_edges_iterator all_edges_begin(); 

/*! 
Past-the-end iterator. 
*/ 
All_edges_iterator all_edges_end(); 

/*! 
Starts at an arbitrary face. 
*/ 
All_faces_iterator all_faces_begin(); 

/*! 
Past-the-end iterator. 
*/ 
All_faces_iterator all_faces_end(); 

/// @} 

/// \name Site Iterators 
/// The following iterators allow respectively to visit all
/// sites. These iterators are non-mutable, bidirectional and their
/// value type is `Site_2`. They are all invalidated by any change in
/// the segment Delaunay graph.
/// @{

/*! 
Starts at an arbitrary input site. 
*/ 
Input_sites_iterator input_sites_begin(); 

/*! 
Past-the-end iterator. 
*/ 
Input_sites_iterator input_sites_end(); 

/*! 
Starts at an arbitrary output site. 
*/ 
Output_sites_iterator output_sites_begin(); 

/*! 
Past-the-end iterator. 
*/ 
Output_sites_iterator output_sites_end(); 

/// @} 

/// \name Face, Edge and Vertex Circulators 
/// The `Segment_Delaunay_graph_2` class also provides circulators
/// that allow to visit respectively all faces or edges incident to a
/// given vertex or all vertices adjacent to a given vertex. These
/// circulators are non-mutable and bidirectional. The operator
/// `operator++` moves the circulator counterclockwise around the
/// vertex while the `operator-` moves clockwise. A face circulator is
/// invalidated by any modification of the face pointed to. An edge
/// circulator is invalidated by any modification in one of the two
/// faces incident to the edge pointed to. A vertex circulator is
/// invalidated by any modification in any of the faces adjacent to
/// the vertex pointed to.
/// @{

/*! 
Starts at an arbitrary face incident 
to `v`. 
*/ 
Face_circulator incident_faces(Vertex_handle v); 

/*! 
Starts at face `f`. 
\pre Face `f` is incident to vertex `v`. 
*/ 
Face_circulator incident_faces(Vertex_handle v, Face_handle f); 

/*! 
Starts at an arbitrary edge incident 
to `v`. 
*/ 
Edge_circulator incident_edges(Vertex_handle v); 

/*! 
Starts at the first edge of `f` incident to 
`v`, in counterclockwise order around `v`. 
\pre Face `f` is incident to vertex `v`. 
*/ 
Edge_circulator incident_edges(Vertex_handle v, Face_handle f); 

/*! 
Starts at an arbitrary vertex incident 
to `v`. 
*/ 
Vertex_circulator incident_vertices(Vertex_handle v); 

/*! 
Starts at the first vertex of `f` adjacent to `v` 
in counterclockwise order around `v`. 
\pre Face `f` is incident to vertex `v`. 
*/ 
Vertex_circulator incident_vertices(Vertex_handle v, Face_handle f); 

/// @} 

/// \name Predicates 
/// The class `Segment_Delaunay_graph_2` provides methods to test the
/// finite or infinite character of any feature.
/// @{

/*! 
`true`, iff `v` is the `infinite_vertex`. 
*/ 
bool is_infinite(Vertex_handle v) const; 

/*! 
`true`, iff face `f` is infinite. 
*/ 
bool is_infinite(Face_handle f) const; 

/*! 
`true`, iff edge `(f,i)` is infinite. 
*/ 
bool is_infinite(Face_handle f, int i) const; 

/*! 
`true`, iff edge `e` is infinite. 
*/ 
bool is_infinite(Edge e) const; 

/*! 
`true`, iff edge `*ec` is infinite. 
*/ 
bool is_infinite(Edge_circulator ec) const; 

/// @} 

/// \name Insertion 
/// @{

/*! 
Inserts the sites in the range 
[`first`,`beyond`). The number of additional sites inserted in 
the Delaunay graph is returned. `Input_iterator` must be a model of 
`InputIterator` and its value type must be 
either `Point_2` or `Site_2`. 
*/ 
template< class Input_iterator > 
size_type insert(Input_iterator first, Input_iterator beyond); 

/*! 
Same as the previous method. `Input_iterator` must be a model of 
`InputIterator` and its value type must be 
either `Point_2` or `Site_2`. 
*/ 
template< class Input_iterator > 
size_type insert(Input_iterator first, Input_iterator beyond, Tag_false); 

/*! 
Inserts the sites in the range 
[`first`,`beyond`) after performing a random shuffle on 
them. The number of additional sites inserted in the Delaunay graph is 
returned. `Input_iterator` must be a model of 
`InputIterator` and its value type must be 
either `Point_2` or `Site_2`. 
*/ 
template< class Input_iterator > 
size_type insert(Input_iterator first, Input_iterator beyond, Tag_true); 

/*! 
Inserts the 
point `p` in the segment Delaunay graph. If `p` has already 
been inserted, then the vertex handle of its already inserted copy is 
returned. If `p` has not been inserted yet, the vertex handle of 
`p` is returned. 
*/ 
Vertex_handle insert(Point_2 p); 

/*! 
Inserts `p` in the segment Delaunay graph using the site 
associated with `vnear` as an estimate for the nearest neighbor 
of `p`. The vertex handle returned has the same semantics as 
the vertex handle returned by the method 
`Vertex_handle insert(Point_2 p)`. 
*/ 
Vertex_handle insert(Point_2 p, Vertex_handle vnear); 

/*! 
Inserts the 
closed segment with endpoints `p1` and `p2` in the segment 
Delaunay graph. If the segment has already been inserted in the 
Delaunay graph then the vertex handle of its already inserted copy is 
returned. If the segment does not intersect any segment in the 
existing diagram, the vertex handle corresponding to its 
corresponding open segment is returned. Finally, if the segment 
intersects other segments in the existing Delaunay graph, the 
vertex handle to one of its open subsegments is returned. 
*/ 
Vertex_handle insert(Point_2 p1, Point_2 p2); 

/*! 
Inserts the segment whose endpoints are `p1` and `p2` 
in the segment Delaunay graph using the site 
associated with `vnear` as an estimate for the nearest neighbor 
of `p1`. The vertex handle returned has the same semantics as the 
vertex handle returned by the method 
`Vertex_handle insert(Point_2 p1, Point_2 p2)`. 
*/ 
Vertex_handle insert(Point_2 p1, Point_2 p2, Vertex_handle 
vnear); 

/*! 
Inserts the site `s` in the 
segment Delaunay graph. The vertex handle returned has the same 
semantics as the vertex handle returned by the methods 
`Vertex_handle insert(Point_2 p)` and `Vertex_handle insert(Point_2 p1, Point_2 p2)`, depending on whether `s` 
represents a point or a segment respectively. 
\pre `s.is_input()` must be `true`. 
*/ 
Vertex_handle insert(Site_2 s); 

/*! 
Inserts `s` in the segment Delaunay graph using the site 
associated with `vnear` as an estimate for the nearest neighbor of 
`s`, if `s` is a point, or the first endpoint of `s`, if 
`s` is a segment. The vertex handle returned has the same 
semantics as the vertex handle returned by the method 
`Vertex_handle insert(Site_2 s)`. 
\pre `s.is_input()` must be `true`. 
*/ 
Vertex_handle insert(Site_2 s, Vertex_handle 
vnear); 

/// @} 

/// \name Nearest neighbor location 
/// @{

/*! 
Finds the nearest neighbor of the point `p`. In other words it 
finds the site whose segment Voronoi diagram cell contains 
`p`. Ties are broken arbitrarily and one of the nearest neighbors 
of `p` is returned. If there are no sites in the 
segment Delaunay graph `Vertex_handle()` is returned. 
*/ 
Vertex_handle nearest_neighbor(Point_2 p); 

/*! 
Finds the nearest neighbor of the point 
`p` using the site associated with `vnear` as an 
estimate for the nearest neighbor of `p`. Ties are broken 
arbitrarily and one of the nearest neighbors of `p` is 
returned. If there are no sites in the segment Delaunay graph 
`Vertex_handle()` is returned. 
*/ 
Vertex_handle nearest_neighbor(Point_2 p, 
Vertex_handle vnear); 

/// @} 

/// \name I/O 
/// @{

/*! 
Draws the segment Voronoi 
diagram to the stream `str`. The following operators must be 
defined: 

`Stream& operator<<(Stream&, Gt::Segment_2)` 

`Stream& operator<<(Stream&, Gt::Ray_2)` 

`Stream& operator<<(Stream&, Gt::Line_2)` 

*/ 
template < class Stream > 
Stream& draw_dual(Stream& str); 

/*! 
Draws the segment Voronoi 
diagram to the stream `str`, except the edges of the diagram 
corresponding to a segment and its endpoints. 
The following operators must be defined: 

`Stream& operator<<(Stream&, Gt::Segment_2)` 

`Stream& operator<<(Stream&, Gt::Ray_2)` 

`Stream& operator<<(Stream&, Gt::Line_2)` 

*/ 
template < class Stream > 
Stream& draw_skeleton(Stream& str); 

/*! 
Draws the edge `e` of 
the segment Voronoi diagram to the stream `str`. 
The following operators must be defined: 

`Stream& operator<<(Stream&, Gt::Segment_2)` 

`Stream& operator<<(Stream&, Gt::Ray_2)` 

`Stream& operator<<(Stream&, Gt::Line_2)` 
\pre `e` must be a finite edge. 
*/ 
template< class Stream > 
Stream& draw_dual_edge(Edge e, Stream& str); 

/*! 
Draws the edge `*ec` of the segment Voronoi diagram to the stream 
`str`. 
The following operators must be defined: 

`Stream& operator<<(Stream&, Gt::Segment_2)` 

`Stream& operator<<(Stream&, Gt::Ray_2)` 

`Stream& operator<<(Stream&, Gt::Line_2)` 
\pre `*ec` must be a finite edge. 
*/ 
template< class Stream > 
Stream& draw_dual_edge(Edge_circulator ec, Stream& str); 

/*! 
Draws the edge `*eit` of the segment Voronoi diagram to the 
stream `str`. 
The following operators must be defined: 

`Stream& operator<<(Stream&, Gt::Segment_2)` 

`Stream& operator<<(Stream&, Gt::Ray_2)` 

`Stream& operator<<(Stream&, Gt::Line_2)` 
\pre `*eit` must be a finite edge. 
*/ 
template< class Stream > 
Stream& draw_dual_edge(All_edges_iterator eit, Stream& str); 

/*! 
Draws the edge `*eit` of the segment Voronoi diagram to the 
stream `str`. 
The following operators must be defined: 

`Stream& operator<<(Stream&, Gt::Segment_2)` 

`Stream& operator<<(Stream&, Gt::Ray_2)` 

`Stream& operator<<(Stream&, Gt::Line_2)` 
*/ 
template< class Stream > 
Stream& draw_dual_edge(Finite_edges_iterator eit, Stream& str); 

/*! 
Writes the current 
state of the segment Delaunay graph to an output stream. In particular, 
all sites in the diagram are written to the stream (represented 
through appropriate input sites), as well as the underlying 
combinatorial data structure. 
*/ 
void file_output(std::ostream& os); 

/*! 
Reads the state of the 
segment Delaunay graph from an input stream. 
*/ 
void file_input(std::istream& is); 

/*! 
Writes the current state of the segment Delaunay graph to an output stream. 
*/ 
std::ostream& operator<<(std::ostream& os, Segment_Delaunay_graph_2<Gt,DS> sdg); 

/*! 
Reads the state of the segment Delaunay graph from an input stream. 
*/ 
std::istream& operator>>(std::istream& is, Segment_Delaunay_graph_2<Gt,DS> sdg); 

/// @} 

/// \name Validity check 
/// @{

/*! 
Checks the validity of the segment Delaunay graph. If `verbose` 
is `true` a short message is sent to `std::cerr`. If 
`level` is 0, only the data structure is validated. If 
`level` is 1, then both the data structure and the segment 
Delaunay graph are validated. Negative values of `level` always 
return true, and values greater than 1 are equivalent to `level` 
being 1. 
*/ 
bool is_valid(bool verbose = false, int level = 1); 

/// @} 

/// \name Miscellaneous 
/// @{

/*! 
Clears all contents of the segment Delaunay graph. 
*/ 
void clear(); 

/*! 
The segment Delaunay graphs 
`other` and `sdg` are swapped. `sdg`.`swap(other)` should 
be preferred to `sdg``= other` or to `sdg``(other)` if 
`other` is deleted afterwards. 
*/ 
void swap(Segment_Delaunay_graph_2<Gt,DS> 
other); 

/// @}

}; /* end Segment_Delaunay_graph_2 */
} /* end namespace CGAL */
