/*
 * vim:expandtab:shiftwidth=8:tabstop=8:
 */

/**
 * \file    pnfs_nfsv41_macros.h
 * \author  $Author: deniel $
 *
 *
 */
#ifndef _PNFS_NFSV41_MACROS_H
#define _PNFS_NFSV41_MACROS_H

#ifdef _SOLARIS
#include "solaris_port.h"
#endif                          /* _SOLARIS */

#include <string.h>
#include <signal.h>


#ifdef _USE_GSSRPC
#include <gssrpc/rpc.h>
#else
#include <rpc/rpc.h>
#endif

#include "PNFS/LAYOUT4_NFSV4_1_FILES/pnfs_layout4_nfsv4_1_files.h"


#define PRINT_HANDLE( tag, handle )                         \
do {                                                        \
 char outstr[1024] ;                                        \
 snprintHandle(outstr, 1024, handle) ;                      \
 printf( "============> %s : handle=%s\n", tag, outstr ) ;  \
} while( 0 )

/* Free a compound */
#define COMPOUNDV41_ARG_FREE \
do { Mem_Free( argcompound.argarray_val ) ;} while( 0 )

#define COMPOUNDV41_ARG_ADD_OP_EXCHANGEID( argcompound, __clientowner )                                                                           \
do {                                                                                                                                              \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_EXCHANGE_ID ;                                              \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opexchange_id.eia_clientowner = __clientowner ;               \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opexchange_id.eia_flags = 0 ;                                 \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opexchange_id.eia_state_protect.spa_how = SP4_NONE ;          \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opexchange_id.eia_client_impl_id.eia_client_impl_id_len = 0 ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opexchange_id.eia_client_impl_id.eia_client_impl_id_val = 0 ; \
  argcompound.argarray.argarray_len += 1 ;                                                                                                        \
} while( 0 )

#define COMPOUNDV41_ARG_ADD_OP_CREATESESSION( argcompound, __clientid )                                                                                        \
do {                                                                                                                                                           \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_CREATE_SESSION ;                                                         \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_clientid = __clientid ;                               \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_sequence = 1 ;                                        \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_flags = CREATE_SESSION4_FLAG_PERSIST ;                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_fore_chan_attrs.ca_headerpadsize = 0 ;                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_fore_chan_attrs.ca_maxrequestsize = 4195348 ;         \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_fore_chan_attrs.ca_maxresponsesize = 4195348 ;        \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_fore_chan_attrs.ca_maxresponsesize_cached = 4195348 ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_fore_chan_attrs.ca_maxoperations = 8 ;                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_fore_chan_attrs.ca_maxrequests = 16 ;                 \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_fore_chan_attrs.ca_rdma_ird.ca_rdma_ird_len = 0 ;     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_fore_chan_attrs.ca_rdma_ird.ca_rdma_ird_val = 0 ;     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_back_chan_attrs.ca_headerpadsize = 0 ;                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_back_chan_attrs.ca_maxrequestsize = 4195348 ;         \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_back_chan_attrs.ca_maxresponsesize = 4195348 ;        \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_back_chan_attrs.ca_maxresponsesize_cached = 4195348 ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_back_chan_attrs.ca_maxoperations = 2 ;                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_back_chan_attrs.ca_maxrequests = 1 ;                  \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_back_chan_attrs.ca_rdma_ird.ca_rdma_ird_len = 0 ;     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_back_chan_attrs.ca_rdma_ird.ca_rdma_ird_val = 0 ;     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_cb_program = 0x40000000 ;                             \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_sec_parms.csa_sec_parms_len = 0 ;                     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate_session.csa_sec_parms.csa_sec_parms_val = 0 ;                     \
  argcompound.argarray.argarray_len += 1 ;                                                                                                                     \
} while( 0 ) ////Poursuivre 

/* OP specific macros */
#define COMPOUNDV41_ARG_ADD_OP_PUTROOTFH( argcompound )                                             \
do {                                                                                               \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_PUTROOTFH ; \
  argcompound.argarray.argarray_len += 1 ;                                                         \
} while( 0 )


#define COMPOUNDV41_ARG_ADD_OP_OPEN_NOCREATE( argcompound, __seqid, inclientid, inaccess, inname, __owner_val, __owner_len )             \
do {                                                                                                                                    \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_OPEN ;                                           \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.seqid = __seqid ;                            \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.share_access = OPEN4_SHARE_ACCESS_BOTH ;     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.share_deny = OPEN4_SHARE_DENY_NONE ;         \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.owner.clientid = inclientid ;                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.owner.owner.owner_len =  __owner_len  ;      \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.owner.owner.owner_val = __owner_val ;        \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.openhow.opentype = OPEN4_NOCREATE ;          \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.claim.claim = CLAIM_NULL ;                   \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.claim.open_claim4_u.file = inname ;          \
  argcompound.argarray.argarray_len += 1 ;                                                                                              \
} while( 0 )

#define COMPOUNDV41_ARG_ADD_OP_CLOSE( argcompound, __stateid )                                                                                    \
do {                                                                                                                                             \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_CLOSE ;                                                   \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opclose.seqid = __stateid.seqid +1 ;                         \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opclose.open_stateid.seqid = __stateid.seqid ;               \
  memcpy( argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opclose.open_stateid.other, __stateid.other, 12 ) ;  \
  argcompound.argarray.argarray_len += 1 ;                                                                                                       \
} while( 0 )

#define COMPOUNDV41_ARG_ADD_OP_GETATTR( argcompound, bitmap )                                                          \
do {                                                                                                                  \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_GETATTR ;                      \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opgetattr.attr_request = bitmap ; \
  argcompound.argarray.argarray_len += 1 ;                                                                            \
} while( 0 )

#define COMPOUNDV41_ARG_ADD_OP_SETATTR( argcompound, inattr )                                                             \
do {                                                                                                                     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_SETATTR ;                         \
  /* argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opsetattr.stateid */ ;            \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opsetattr.obj_attributes = inattr ;  \
  argcompound.argarray.argarray_len += 1 ;                                                                               \
} while( 0 )

#define COMPOUNDV41_ARG_ADD_OP_GETFH( argcompound )                                                            \
do {                                                                                                          \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_GETFH ;                \
  argcompound.argarray.argarray_len += 1 ;                                                                    \
} while( 0 )

#define COMPOUNDV41_ARG_ADD_OP_PUTFH( argcompound, nfs4fh )                                                    \
do {                                                                                                          \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_PUTFH ;                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opputfh.object = nfs4fh ; \
  argcompound.argarray.argarray_len += 1 ;                                                                    \
} while( 0 )

#define COMPOUNDV41_ARG_ADD_OP_LOOKUP( argcompound, name )                                                     \
do {                                                                                                          \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_LOOKUP ;               \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.oplookup.objname = name ; \
  argcompound.argarray.argarray_len += 1 ;                                                                    \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_LOOKUPP( argcompound )                                             \
do {                                                                                             \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_LOOKUPP ; \
  argcompound.argarray.argarray_len += 1 ;                                                       \
} while ( 0 )


#define COMPOUNDV41_ARG_ADD_OP_ACCESS( argcompound, inaccessflag )                                                    \
do {                                                                                                                 \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_ACCESS ;                      \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opaccess.access = inaccessflag ; \
  argcompound.argarray.argarray_len += 1 ;                                                                           \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_READDIR( argcompound, incookie, innbentry, inverifier, inbitmap  )                                                     \
do {                                                                                                                                                 \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_READDIR ;                                                     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opreaddir.cookie       = incookie ;                              \
  memcpy( argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opreaddir.cookieverf, inverifier, NFS4_VERIFIER_SIZE ) ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opreaddir.dircount     = innbentry*sizeof( entry4 ) ;            \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opreaddir.dircount     = 2048 ;                                  \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opreaddir.maxcount     = innbentry*sizeof( entry4 ) ;            \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opreaddir.maxcount     = 4096 ;                                  \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opreaddir.attr_request = inbitmap ;                              \
  argcompound.argarray.argarray_len += 1 ;                                                                                                           \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_OPEN_CREATE( argcompound, inname, inattrs, inclientid, __owner_val, __owner_len )                                         \
do {                                                                                                                                                    \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_OPEN ;                                                           \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.seqid = 0 ;                                                  \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.share_access = OPEN4_SHARE_ACCESS_BOTH ;                     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.share_deny = OPEN4_SHARE_DENY_NONE ;                         \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.owner.clientid = inclientid ;                                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.owner.owner.owner_len =  __owner_len ;                       \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.owner.owner.owner_val =  __owner_val ;                       \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.openhow.opentype = OPEN4_CREATE ;                            \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.openhow.openflag4_u.how.mode = GUARDED4 ;                    \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.openhow.openflag4_u.how.createhow4_u.createattrs = inattrs ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.claim.claim = CLAIM_NULL ;                                   \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opopen.claim.open_claim4_u.file = inname ;                          \
  argcompound.argarray.argarray_len += 1 ;                                                                                                              \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_MKDIR( argcompound, inname, inattrs )                                                  \
do {                                                                                                                 \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_CREATE ;                      \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate.objtype.type = NF4DIR ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate.objname = inname ;      \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate.createattrs = inattrs ; \
  argcompound.argarray.argarray_len += 1 ;                                                                           \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_SYMLINK( argcompound, inname, incontent, inattrs )                                                          \
do {                                                                                                                                      \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_CREATE ;                                           \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate.objtype.type = NF4LNK ;                      \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate.objtype.createtype4_u.linkdata = incontent ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate.objname = inname ;                           \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opcreate.createattrs = inattrs ;                      \
  argcompound.argarray.argarray_len += 1 ;                                                                                                \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_LINK( argcompound, inname )                                                     \
do {                                                                                                          \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_LINK ;                 \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.oplink.newname = inname ; \
  argcompound.argarray.argarray_len += 1 ;                                                                    \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_REMOVE( argcompound, inname )                                                    \
do {                                                                                                           \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_REMOVE ;                \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opremove.target = inname ; \
  argcompound.argarray.argarray_len += 1 ;                                                                     \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_RENAME( argcompound, inoldname, innewname )                                          \
do {                                                                                                               \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_RENAME ;                    \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.oprename.oldname = inoldname ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.oprename.newname = innewname ; \
  argcompound.argarray.argarray_len += 1 ;                                                                         \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_READLINK( argcompound )                                             \
do {                                                                                              \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_READLINK ; \
  argcompound.argarray.argarray_len += 1 ;                                                        \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_SAVEFH( argcompound )                                             \
do {                                                                                            \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_SAVEFH ; \
  argcompound.argarray.argarray_len += 1 ;                                                      \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_RESTOREFH( argcompound )                                             \
do {                                                                                               \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_RESTOREFH ; \
  argcompound.argarray.argarray_len += 1 ;                                                         \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_READ( argcompound, instateid, inoffset, incount )                                                                \
do {                                                                                                                                           \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_READ ;                                                  \
  memcpy( &argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opread.stateid, instateid, sizeof( stateid4 ) ) ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opread.offset = inoffset ;                                 \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opread.count  = incount ;                                  \
  argcompound.argarray.argarray_len += 1 ;                                                                                                     \
} while ( 0 )

#define COMPOUNDV41_ARG_ADD_OP_WRITE( argcompound, instateid, inoffset, indatabuffval, indatabufflen )                                           \
do {                                                                                                                                            \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].argop = NFS4_OP_WRITE ;                                                  \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opwrite.stable= DATA_SYNC4 ;                                \
  memcpy( &argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opwrite.stateid, instateid, sizeof( stateid4 ) ) ; \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opwrite.offset = inoffset ;                                 \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opwrite.data.data_val = indatabuffval ;                     \
  argcompound.argarray.argarray_val[argcompound.argarray.argarray_len].nfs_argop4_u.opwrite.data.data_len = indatabufflen ;                     \
  argcompound.argarray.argarray_len += 1 ;                                                                                                      \
} while ( 0 )

#define COMPOUNDV41_EXECUTE_SIMPLE( pclient, argcompound, rescompound )    \
   clnt_call( pclient->rpc_client, NFSPROC4_COMPOUND,                      \
              (xdrproc_t)xdr_COMPOUND4args, (caddr_t)&argcompound,         \
              (xdrproc_t)xdr_COMPOUND4res,  (caddr_t)&rescompound,         \
              timeout )

#endif                          /* _PNFS_NFSV41_MACROS_H */