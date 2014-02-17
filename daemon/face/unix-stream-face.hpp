/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (C) 2014 Named Data Networking Project
 * See COPYING for copyright and distribution information.
 */

#ifndef NFD_FACE_UNIX_STREAM_FACE_HPP
#define NFD_FACE_UNIX_STREAM_FACE_HPP

#include "stream-face.hpp"

namespace nfd
{

/**
 * \brief Implementation of Face abstraction that uses stream-oriented
 *        Unix domain sockets as underlying transport mechanism
 */
class UnixStreamFace : public StreamFace<boost::asio::local::stream_protocol>
{
public:
  typedef boost::asio::local::stream_protocol protocol;

  explicit
  UnixStreamFace(const shared_ptr<protocol::socket>& socket);

  /** \brief Get whether face is connected to a local app
   *
   *  Always true for a UnixStreamFace.
   */
  virtual bool
  isLocal() const;
};

} // namespace nfd

#endif // NFD_FACE_UNIX_STREAM_FACE_HPP