// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: echo.proto

#include "echo.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace echo {
class ReqDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Req> _instance;
} _Req_default_instance_;
class RepDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Rep> _instance;
} _Rep_default_instance_;
class ReqLenDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ReqLen> _instance;
} _ReqLen_default_instance_;
}  // namespace echo
static void InitDefaultsscc_info_Rep_echo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::echo::_Rep_default_instance_;
    new (ptr) ::echo::Rep();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::echo::Rep::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Rep_echo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Rep_echo_2eproto}, {}};

static void InitDefaultsscc_info_Req_echo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::echo::_Req_default_instance_;
    new (ptr) ::echo::Req();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::echo::Req::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Req_echo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Req_echo_2eproto}, {}};

static void InitDefaultsscc_info_ReqLen_echo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::echo::_ReqLen_default_instance_;
    new (ptr) ::echo::ReqLen();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::echo::ReqLen::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ReqLen_echo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ReqLen_echo_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_echo_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_echo_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_echo_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_echo_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::echo::Req, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::echo::Req, message_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::echo::Rep, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::echo::Rep, message_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::echo::ReqLen, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::echo::ReqLen, message_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::echo::Req)},
  { 6, -1, sizeof(::echo::Rep)},
  { 12, -1, sizeof(::echo::ReqLen)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::echo::_Req_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::echo::_Rep_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::echo::_ReqLen_default_instance_),
};

const char descriptor_table_protodef_echo_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\necho.proto\022\004echo\"\026\n\003Req\022\017\n\007message\030\001 \001"
  "(\014\"\026\n\003Rep\022\017\n\007message\030\001 \001(\014\"\031\n\006ReqLen\022\017\n\007"
  "message\030\001 \001(\0052I\n\004Echo\022\036\n\004echo\022\t.echo.Req"
  "\032\t.echo.Rep\"\000\022!\n\004read\022\014.echo.ReqLen\032\t.ec"
  "ho.Rep\"\000b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_echo_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_echo_2eproto_sccs[3] = {
  &scc_info_Rep_echo_2eproto.base,
  &scc_info_Req_echo_2eproto.base,
  &scc_info_ReqLen_echo_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_echo_2eproto_once;
static bool descriptor_table_echo_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_echo_2eproto = {
  &descriptor_table_echo_2eproto_initialized, descriptor_table_protodef_echo_2eproto, "echo.proto", 176,
  &descriptor_table_echo_2eproto_once, descriptor_table_echo_2eproto_sccs, descriptor_table_echo_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_echo_2eproto::offsets,
  file_level_metadata_echo_2eproto, 3, file_level_enum_descriptors_echo_2eproto, file_level_service_descriptors_echo_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_echo_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_echo_2eproto), true);
namespace echo {

// ===================================================================

void Req::InitAsDefaultInstance() {
}
class Req::_Internal {
 public:
};

Req::Req()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:echo.Req)
}
Req::Req(const Req& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  message_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_message().empty()) {
    message_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
  // @@protoc_insertion_point(copy_constructor:echo.Req)
}

void Req::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Req_echo_2eproto.base);
  message_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Req::~Req() {
  // @@protoc_insertion_point(destructor:echo.Req)
  SharedDtor();
}

void Req::SharedDtor() {
  message_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Req::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Req& Req::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Req_echo_2eproto.base);
  return *internal_default_instance();
}


void Req::Clear() {
// @@protoc_insertion_point(message_clear_start:echo.Req)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  message_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* Req::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes message = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_message();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Req::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:echo.Req)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes message = 1;
  if (this->message().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_message(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:echo.Req)
  return target;
}

size_t Req::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:echo.Req)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes message = 1;
  if (this->message().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_message());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Req::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:echo.Req)
  GOOGLE_DCHECK_NE(&from, this);
  const Req* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Req>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:echo.Req)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:echo.Req)
    MergeFrom(*source);
  }
}

void Req::MergeFrom(const Req& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:echo.Req)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.message().size() > 0) {

    message_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
}

void Req::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:echo.Req)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Req::CopyFrom(const Req& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:echo.Req)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Req::IsInitialized() const {
  return true;
}

void Req::InternalSwap(Req* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  message_.Swap(&other->message_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata Req::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Rep::InitAsDefaultInstance() {
}
class Rep::_Internal {
 public:
};

Rep::Rep()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:echo.Rep)
}
Rep::Rep(const Rep& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  message_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_message().empty()) {
    message_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
  // @@protoc_insertion_point(copy_constructor:echo.Rep)
}

void Rep::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Rep_echo_2eproto.base);
  message_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Rep::~Rep() {
  // @@protoc_insertion_point(destructor:echo.Rep)
  SharedDtor();
}

void Rep::SharedDtor() {
  message_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Rep::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Rep& Rep::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Rep_echo_2eproto.base);
  return *internal_default_instance();
}


void Rep::Clear() {
// @@protoc_insertion_point(message_clear_start:echo.Rep)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  message_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* Rep::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes message = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_message();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Rep::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:echo.Rep)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes message = 1;
  if (this->message().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_message(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:echo.Rep)
  return target;
}

size_t Rep::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:echo.Rep)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes message = 1;
  if (this->message().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_message());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Rep::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:echo.Rep)
  GOOGLE_DCHECK_NE(&from, this);
  const Rep* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Rep>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:echo.Rep)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:echo.Rep)
    MergeFrom(*source);
  }
}

void Rep::MergeFrom(const Rep& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:echo.Rep)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.message().size() > 0) {

    message_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
}

void Rep::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:echo.Rep)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Rep::CopyFrom(const Rep& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:echo.Rep)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Rep::IsInitialized() const {
  return true;
}

void Rep::InternalSwap(Rep* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  message_.Swap(&other->message_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata Rep::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ReqLen::InitAsDefaultInstance() {
}
class ReqLen::_Internal {
 public:
};

ReqLen::ReqLen()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:echo.ReqLen)
}
ReqLen::ReqLen(const ReqLen& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  message_ = from.message_;
  // @@protoc_insertion_point(copy_constructor:echo.ReqLen)
}

void ReqLen::SharedCtor() {
  message_ = 0;
}

ReqLen::~ReqLen() {
  // @@protoc_insertion_point(destructor:echo.ReqLen)
  SharedDtor();
}

void ReqLen::SharedDtor() {
}

void ReqLen::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ReqLen& ReqLen::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ReqLen_echo_2eproto.base);
  return *internal_default_instance();
}


void ReqLen::Clear() {
// @@protoc_insertion_point(message_clear_start:echo.ReqLen)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  message_ = 0;
  _internal_metadata_.Clear();
}

const char* ReqLen::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 message = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          message_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ReqLen::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:echo.ReqLen)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 message = 1;
  if (this->message() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_message(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:echo.ReqLen)
  return target;
}

size_t ReqLen::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:echo.ReqLen)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 message = 1;
  if (this->message() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_message());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ReqLen::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:echo.ReqLen)
  GOOGLE_DCHECK_NE(&from, this);
  const ReqLen* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ReqLen>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:echo.ReqLen)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:echo.ReqLen)
    MergeFrom(*source);
  }
}

void ReqLen::MergeFrom(const ReqLen& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:echo.ReqLen)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.message() != 0) {
    _internal_set_message(from._internal_message());
  }
}

void ReqLen::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:echo.ReqLen)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ReqLen::CopyFrom(const ReqLen& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:echo.ReqLen)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ReqLen::IsInitialized() const {
  return true;
}

void ReqLen::InternalSwap(ReqLen* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(message_, other->message_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ReqLen::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace echo
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::echo::Req* Arena::CreateMaybeMessage< ::echo::Req >(Arena* arena) {
  return Arena::CreateInternal< ::echo::Req >(arena);
}
template<> PROTOBUF_NOINLINE ::echo::Rep* Arena::CreateMaybeMessage< ::echo::Rep >(Arena* arena) {
  return Arena::CreateInternal< ::echo::Rep >(arena);
}
template<> PROTOBUF_NOINLINE ::echo::ReqLen* Arena::CreateMaybeMessage< ::echo::ReqLen >(Arena* arena) {
  return Arena::CreateInternal< ::echo::ReqLen >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
