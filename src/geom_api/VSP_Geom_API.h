//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//

// API.h: interface for the Vehicle Class and Vehicle Mgr Singleton.
// J.R Gloudemans
//
//////////////////////////////////////////////////////////////////////

#if !defined(VSPAPI__INCLUDED_)
#define VSPAPI__INCLUDED_



#include "APIErrorMgr.h"
#include "Vec3d.h"

#include <string>
#include <stack>
#include <vector>


using std::string;
using std::stack;
using std::vector;

namespace vsp
{

//======================== API Functions ================================//
extern void VSPCheckSetup();
extern void VSPRenew();

//======================== File I/O ================================//
// jrg finish this stuff
//extern void SetWorkingDir( const string & dir_name );
extern void ReadVSPFile( const string & file_name );
extern void WriteVSPFile( const string & file_name, int set = SET_ALL );
//extern void SetOutputFileName( int file_type, const string & file_name );

//======================== GUI Functions ================================//
extern void StartGui( );

//======================== Geom Functions ================================//
extern std::vector< std::string > GetGeomTypes();
extern string AddGeom( const string & type, const string & parent = string() );
extern void CutGeomToClipboard( const string & geom_id );
extern void CopyGeomToClipboard( const string & geom_id );
extern void PasteGeomClipboard( const string & parent = string() );
extern std::vector< std::string > FindGeoms();
extern std::vector< std::string > FindGeoms( const string & name );
extern string FindGeom( const string & name, int index );
extern void SetGeomName( const string & geom_id, const string & name );
extern string GetGeomName( const string & geom_id );
extern std::vector< std::string > GetGeomParmIDs( const string & geom_id );
extern string GetParm( const string & geom_id, const string & name, const string & group );
extern int GetNumXSecSurfs( const string & geom_id );

//======================== XSecSurf ================================//
extern string GetXSecSurf( const string & geom_id, int index );
extern int GetNumXSec( const string & xsec_surf_id );
extern string GetXSec( const string & xsec_surf_id, int xsec_index );
extern void CutXSec( const string & xsec_surf_id, int xsec_index );
extern void CopyXSec( const string & xsec_surf_id, int xsec_index );
extern void PasteXSec( const string & xsec_surf_id, int xsec_index );
extern string InsertXSec( const string & xsec_surf_id, int type, int xsec_index );
extern void ChangeXSecType( const string & xsec_surf_id, int xsec_index, int type );

//======================== XSec ================================//
extern int GetXSecType( const string& xsec_id );
extern double GetXSecWidth( const string& xsec_id );
extern double GetXSecHeight( const string& xsec_id );
extern void SetXSecWidthHeight( const string& xsec_id, double w, double h );
//extern vector< string > GetXSecParmIDs( const string& xsec_id );
extern string GetXSecParm( const string& xsec_id, const string& name );
extern std::vector<vec3d> ReadFileXSec( const string& xsec_id, const string& file_name );
extern void SetXSecPnts( const string& xsec_id, std::vector< vec3d > & pnt_vec );

//======================== Sets ================================//
extern int GetNumSets();
extern void SetSetName( int index, const string& name );
extern string GetSetName( int index );
extern std::vector< std::string > GetGeomSet( int index );
extern std::vector< std::string > GetGeomSet( const string & name );

//======================== Parm Functions ================================//
extern bool ValidParm( const string & id );
extern double SetParmVal( const string & parm_id, double val, bool update = true );
extern double SetParmVal( const string & geom_id, const string & name, const string & group, double val, bool update = true );
extern double GetParmVal( const string & parm_id );
extern void SetParmUpperLimit( const string & parm_id, double val );
extern double GetParmUpperLimit( const string & parm_id );
extern void SetParmLowerLimit( const string & parm_id, double val );
extern double GetParmLowerLimit( const string & parm_id );
extern int GetParmType( const string & parm_id );
extern string GetParmName( const string & parm_id );
extern string GetParmContainer( const string & parm_id );









}           // End vsp namespace


#endif // !defined(VSPAPI__INCLUDED_)




/** \mainpage VSP API and Application
 *
 * VSP is a parametric aircraft geometry tool originally developed by NASA and
 * released as open-source software in January 2012.  VSP is currently being
 * refactored, redesigned, and rewritten to make the code more modular and
 * maintainable, and to provide an API such that other applications may access
 * the core geometry capability VSP provides.
 *
 * One of the primary goals of this refactoring is to separate the geometry
 * functions of VSP from the GUI and OpenGL 3D graphics.  Once complete, this
 * separation will enable batch-mode applications with the capabilities of VSP
 * to be compiled and run on computers where graphics libraries are not
 * welcome.  In addition, this will allow other dedicated applications to access
 * VSP's unique geometric capability without inheriting all of the GUI and
 * graphics.
 *
 * VSP's code is organized into three main groups.
 *  - util provides a set of core data structures which find common use.
 *  - geom_core provides the core geometry data structures and algorithms.
 *  - gui_and_draw provides all of the FLTK GUI code and OpenGL 3D drawing code.
 *
 * There must be no dependencies of geom_core and util on gui_and_draw.  However,
 * gui_and_draw can depend on util and geom_core.  In an interactive application,
 * there are times where geom_core needs to communicate with gui_and_draw -- for
 * example, to trigger an update.  VSP uses a subscription based message passing
 * capability in MessageMgr to support this.
 *
 * Some good places to start browsing the code:
 *  - MessageMgr is the message passing capability.
 *  - Vehicle is the main class for the geom_core.
 *  - Geom is the main base class for geometry entities.
 *  - Parm is the class for all parameters.
 *  - Parms are managed through ParmMgr, an alias for ParmMgrSingleton.
 *  - DrawObj s are created by Vehicle and drawn by VirtGlWindow.
 *
 */