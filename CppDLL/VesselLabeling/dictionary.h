/**
* @file dictionary.h
* @brief AzzñReiNXÌwb_t@C
* @version 3.0
* @author ¼Ã®åw îñÈw¤È fBAÈwêU X¤º   351203192   ¼ú± NN
* @date 2013/10/18
*/

#ifndef _TMATSU_DICTIONARY_H_
#define _TMATSU_DICTIONARY_H_

#include <list>

namespace tmatsu 
{
	/// @brief vfð\[gµÈ¢AzzñÌReiNX
	/// @tparam KeyType L[^
	/// @tparam ValueType f[^^
	/// @tparam Allocator AP[^^DKèlÍSTLÌftHgAP[^
	template < class KeyType, class ValueType, class Allocator = std::allocator< std::pair< KeyType, ValueType > > >
	class dictionary : public std::list< std::pair< KeyType, ValueType >, Allocator >
	{
	public:
		typedef KeyType key_type; ///< @brief L[
		typedef ValueType mapped_type; ///< @brief l

		/// @brief AzzñÉÜÜêÄ¢È¢L[ðQÆµæ¤Æ·éÆ°çêéáO
		class invalid_key : public std::exception
		{
		};
	public:
		virtual ~dictionary();
		bool contains( const KeyType &key )const;
		mapped_type &operator[ ]( const KeyType &key );
		const mapped_type &operator[ ]( const KeyType &key )const;
	};

	/// @brief ®ì³µ
	template< class KeyType, class ValueType, class Allocator >
	inline dictionary< KeyType, ValueType, Allocator >::~dictionary( )
	{
	}

	/// @brief L[ª¶Ý·é©»è·é
	/// @param[in] key »è·éL[
	/// @retval true øÌL[Í¶Ý·é
	/// @retval false øÌL[Í¶ÝµÈ¢		
	template< class KeyType, class ValueType, class Allocator >
	inline bool dictionary< KeyType, ValueType, Allocator >::contains( const KeyType &key )const
	{
		for ( const_iterator iter = begin( ); iter != end( ); iter++ )
		{
			if ( iter->first == key )
			{
				return true;
			}
		}

		return false;
	}

	/// @brief lðæ¾·é
	/// @attention øÌL[ª¶ÝµÈ¢êC invalid_key áOð°é
	/// @attention _ANZXÉÍvfÉäá·éÔªKv
	/// @param[in] key æ¾·élÌL[
	/// @return øÌL[Ìw·lÌQÆ
	template< class KeyType, class ValueType, class Allocator >
	inline typename dictionary< KeyType, ValueType, Allocator >::mapped_type &dictionary< KeyType, ValueType, Allocator >::operator[ ]( const KeyType &key )
	{
		for ( iterator iter = begin( ); iter != end( ); iter++ )
		{
			if ( iter->first == key )
			{
				return iter->second;
			}
		}

		throw invalid_key( );
	}

	/// @brief lðæ¾·é
	/// @attention øÌL[ª¶ÝµÈ¢êC invalid_key áOð°é
	/// @attention _ANZXÉÍvfÉäá·éÔªKv
	/// @param[in] key æ¾·élÌL[
	/// @return øÌL[Ìw·lÌèQÆ
	template< class KeyType, class ValueType, class Allocator >
	inline const typename dictionary< KeyType, ValueType, Allocator >::mapped_type &dictionary< KeyType, ValueType, Allocator >::operator[ ]( const KeyType &key )const
	{
		for ( const_iterator iter = begin( ); iter != end( ); iter++ )
		{
			if ( iter->first == key )
			{
				return iter->second;
			}
		}

		throw invalid_key( );
	}
}

#endif //_TMATSU_DICTIONARY_H_