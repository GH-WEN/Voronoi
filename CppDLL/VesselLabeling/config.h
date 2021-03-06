/**
* @file config.h
* @brief ÝèÌwb_t@C
* @version 3.0
* @author ¼Ã®åw îñÈw¤È fBAÈwêU X¤º   351203192   ¼ú± NN
* @date 2013/10/18
*/

#ifndef _TMATSU_CONFIG_H_
#define _TMATSU_CONFIG_H_

#define _TARGET_HYPOGASTRIC ///< @brief º ®¬ðÎÛÉ·é

#define _CALC_LIKELIHOOD ///< @brief ÞxvZðs¤
#define _CALC_INTEGRITY ///< @brief ®«ðßé
//#define _UPDATE_LIKELIHOOD ///< @brief ÞxXVðs¤
//#define _FIND_MAX_LIKELIHOOD ///< @brief ÅåÌÞxðÂq·ðTõ·é±ÆÉæèÎt¯ðs¤
//#define _SCREEN_OUT_CANDIDATE ///< @brief óâÌÓé¢ÆµÉæèÎt¯ðs¤
//#define _FIND_BIFURCATION ///< @brief ªòðTõ·é±ÆÉæèÎt¯ðs¤
//#define _SELECT_MODEL ///< @brief fIðÉæèÎt¯ðs¤
#define _FIND_OPTIMUM_BRANCHING ///< @brief ÅKªòðßé±ÆÉæèÎt¯ðs¤
//#define _IGNORE_TAIL_SCORE ///< @brief ªòOtÌdÝðvZ·éÆ«I[XRAð³·é
//#define _CORRECT_ERROR ///< @brief ëèù³ðs¤

//#define _WRITE_LIKELIHOOD ///< @brief ÞxðoÍ·é

//#define _EVALUATE_HEAD_ONLY ///< @brief eÇÌÅÌÝ]¿·é
//#define _EVALUATE_LIKELIHOOD_RANKING ///< @brief ÞxÌãÊÉ³ðª éð]¿·é
//#define _EVALUATE_PATTERN ///< @brief ªòp^[ð¯ÊÅ«½©]¿·é
//#define _EVALUATE_EVERY_PATTERN ///< @brief p^[²ÆÉ]¿·é
//#define _EVALUATE_EVERY_CASE ///< @brief Çá²ÆÉ]¿·é

#define _REPORT_IN_ENGLISH ///< @brief ff|[gðpêÅì¬·é

//#define _DEBUG_GRAPH ///< @brief OtÉÖ·éfobOîñðoÍ·é

#define TOPOLOGY 6 ///< @brief g|W
#define LEARN_ITERATION 1000 ///< @brief wKÌJèÔµñ
#define PRUN_THRESHOLD 2 ///< @brief } è·é}Ìæf
#define BOTTOM_THRESHOLD( dpt ) ( ( dpt ) * 0.9 ) ///< @brief °®¬ÌI[}ÌóâÆ·é}ÌI_ÌÅáÌzÀW
#define THICKNESS_THRESHOLD 2.0 ///< @brief °®¬¶Ý»èÌµ«¢l
#define SMV_THRESHOLD( avg ) ( avg ) ///< @brief ã°ÔÃ¬ÌóâÆ·éªØÌÅáÌ}
#define LPV_THRESHOLD( avg ) ( avg ) ///< @brief å¬¶}ÌóâÆ·éªØÌÅáÌ}
#define CROSS_THRESHOLD 2.0 ///< @brief ð·»èÌµ«¢l

#endif //_TMATSU_CONFIG_H_

/**
* @mainpage Ç¼Ît¯vWFNg
* @version 3.0
* @author ¼Ã®åw îñÈw¤È fBAÈwêU X¤º   351203192   ¼ú± NN
* @date 2013/10/18
* 
* @section gp·éÉÍ
*
* @subsection vpeBÌÝè
* 
* MIST ÌCN[hfBNgÌpXðuÇÁÌCN[hfBNgvÉÇÁµÜ· @n
* zconf.h, zlib.h ª éfBNgÌpXðuÇÁÌCN[hfBNgvÉÇÁµÜ· @n
* zlib.lib ª éfBNgÌpXðuÇÁÌCufBNgvÉÇÁµÜ· @n
* zlib.lib ðuÇÁÌË¶t@CvÉÇÁµÜ· @n
*
* @subsection wb_ÌCN[h
* @code
* #include "artery.h" // ®¬ÌÇ¼Ît¯ðs¤
* #include "portal.h" // Ã¬ÌÇ¼Ît¯ðs¤
* @endcode
* 
* @subsection ®¬ÌÎt¯Ìá
* @code
* using namespace tmatsu;
* using namespace tmatsu::artery;
* 
* MarkImage vessel; // ÇÌ}[Næ
* ThicknessImage centerline; // cüæ
* LabelImage labeled_vessel; // ÇÌxæ
* Tree tree; // Ø\¢
* Tree result; // Ît¯ÊØ\¢
* Tree truth; // ³ðØ\¢
* LikelihoodFunction likelihood_func; // ÞxÖ
* Matrix confusion; // Rt[W}gbNX
* 
* // ÇÌ}[NæðÇÝÞ
* if ( !vessel.read( MarkImage::ProgressCallback( ), "\\\\TAKA2\\tmatsu\\ACC_g001\\vessel.uc_raw.gz" ) )
* {
*		std::exit( 1 );
* }
* 
* // ³ðØ\¢ðÇÝÞ
* if ( !truth.read( "\\\\TAKA2\\tmatsu\\ACC_g001\\truth.xml", vessel.get_size( ). vessel.get_pitch( ) ) )
* {
*		std::exit( 1 );
* }
* 
* // ÞxÖðÇÝÞ
* if ( !likelihood_func.read( "\\\\TAKA2\\tmatsu\\ACC_g001" ) )
* {
*		std::exit( 1 );
* }
* 
* // cüðo·é
* vessel.thinning( centerline );
* 
* // Ø\¢ð\z·é
* tree.construct( centerline );
* 
* // Ît¯ðs¤
* tree.labeling( result, likelihood_func );
* 
* // Êð]¿·é
* result.evaluate( confusion, truth );
* 
* // xæð³·é
* result.restore( vessel, labeled_vessel );
* 
* // Ît¯Êð«Þ
* if ( !result.write( "\\\\TAKA2\\tmatsu\\ACC_g001\\result.xml" ) )
* {
*		std::exit( 1 );
* }
* 
* // ]í`®Å«Þ
* if ( !tree.write_tree_info( "\\\\TAKA2\\tmatsu\\ACC_g001\\tree_info.xml", centerline ) )
* {
*		std::exit( 1 );
* }
* 
* if ( !tree.write_centerline_info( "\\\\TAKA2\\tmatsu\\ACC_g001\\centerline_info.xml", centerline ) )
* {
*		std::exit( 1 );
* }
* 
* if ( !tree.write_overlay_info( "\\\\TAKA2\\tmatsu\\ACC_g001\\overlay_info.xml" ) )
* {
*		std::exit( 1 );
* }
* 
* // NewVES`®Å«Þ
* if ( !tree.write_secant_points( "\\\\TAKA2\\tmatsu\\ACC_g001\\sec_pt.csv" ) )
* {
*		std::exit( 1 );
* }
* 
* // ³Êð«Þ
* if ( !labeled_vessel.write( LabelImage::ProgressCallback( ), "\\\\TAKA2\\tmatsu\\ACC_g001\\labeled_vessel.uc_raw.gz" ) )
* {
*		std::exit( 1 );
* }
* @endcode
* 
* @subsection Ã¬ÌwKÌá
* @code
* using namespace tmatsu;
* using namespace tmatsu::portal;
* 
* std::list< FeatureVector > samples; // wKTvXg
* LikelihoodFunction likelihood_func; // ÞxÖ
* 
* // wKTvðÇÝÞ
* for ( size_t i = 2; ; i++ )
* {
*		std::stringstream ss; // XgOXg[
*		std::string hdr_file_name; // wb_t@C¼
*		std::string tree_file_name; // Ø\¢t@C¼
*		Header hdr; // wb_
*		Tree tree; // Ø\¢
*		std::list< FeatureVector > features; // Á¥Ê
* 
*		ss << "\\\\TAKA2\\tmatsu\\ACC_g" << std::setw( 3 ) << std::setfill( '0' ) << i;
*		hdr_file_name = ss.str( ) + "\\vessel.uc_raw.gz.header";
*		tree_file_name = ss.str( ) + "\\tree.xml";
* 
*		// wb_t@CðÇÝÞ
*		if ( !hdr.read( hdr_file_name.c_str( ) ) )
*		{
*			break;
*		}
*
*		// Ø\¢ðÇÝÞ
*		if ( !tree.read( tree_file_name.c_str( ), hdr.get_size( ), hdr.get_pitch( ) ) )
*		{
*			break;
*		}
* 
*		// Á¥Êðo·é
*		tree.extract( features );
*		samples.splice( samples.end( ), features );
* }
* 
* // wK·é
* likelihood_func.learn( samples );
* 
* // ÞxÖð«Þ
* if ( !likelihood_func.write( "\\\\TAKA2\\tmatsu\\ACC_g001" ) )
* {
*		std::exit( 1 );
* }
* @endcode
*
* @section ®ìðÏX·éÉÍ
* tmatsu::tubular::Tree ªØ\¢ðµ¤NXÌîêÆÈÁÄ¢Ü· @n
* Æ©Ìðs¤½ßÉÍÈºÌoÖðÀµ½h¶NXðì¬µÜ· @n
* eÖÌÚ×Ít@XðQÆµÄ­¾³¢
* @code
* tmatsu::tubular::Tree::root_point;
* tmatsu::tubular::Tree::traverse_branch;
* tmatsu::tubular::Tree::reference_branch;
* tmatsu::tubular::Tree::extract_feature;
* tmatsu::tubular::Tree::evaluate_result;
* tmatsu::tubular::Tree::restore_centerline;
* tmatsu::tubular::Tree::restore_bifurcation;
* tmatsu::tubular::Tree::read_branch;
* tmatsu::tubular::Tree::write_branch;
* tmatsu::tubular::Tree::reject_name;
* tmatsu::tubular::Tree::default_likelihood;
* tmatsu::tubular::Tree::name_number;
* tmatsu::tubular::Tree::to_string;
* tmatsu::tubular::Tree::to_index;
* tmatsu::tubular::Tree::to_name;
* @endcode
* Ü½ÈºÌoÖðÀ·é±ÆÅ®ìðg£·é±ÆªÅ«Ü· @n
* KvÈ¯êÎ¢è`Åà\¢Ü¹ñ
* @code
* tmatsu::tubular::Tree::construct_postprocess;
* tmatsu::tubular::Tree::labeling_preprocess;
* tmatsu::tubular::Tree::labeling_postprocess;
* @endcode
* tmatsu::vessel::Tree, tmatsu::artery::Tree, tmatsu::portal::Tree Í±ÌNXðp³µÄ¢Ü· @n
* Ü½±ÌNXÍ tmatsu::tree ðîêÆµSTLReiÌæ¤Éµ¤±ÆªÅ«Ü·
*/